#if defined(_WIN32)

    #include "Windows.h"

    namespace Sys {
        bool IsDebuggerAttached() {
            return IsDebugerPresent();
        }
    }

#elif defined(__linux__)

    #include <unistd.h>
    #include <sys/ptrace.h>
    #include <sys/wait.h>

    namespace Sys {
        bool IsDebuggerAttached() {
            // Spawn a child process that will try to ptrace our current process
            int pid = fork();

            if (pid == -1) {
                return false;
            }

            if (pid == 0) {
                int parentPid = getppid();

                // Try to trace the parent (only one process can a given process so if we are being
                // debugged, the call will fail).
                if (ptrace(PTRACE_ATTACH, parentPid, nullptr, nullptr) == 0) {
                    // No debugger is present so we started tracing. Stop tracing and return false.
                    waitpid(parentPid, nullptr, 0);
                    ptrace(PTRACE_CONT, nullptr, nullptr);
                    ptrace(PTRACE_DETACH, parentPid, nullptr, nullptr);
                    exit(0);
                } else {
                    // Call failed, we are being traced, return true.
                    exit(1);
                }

            } else {
                // Get the result from the child
                int status;
                waitpid(pid, &status, 0);
                return WEXITSTATUS(status);
            }
        }
    }

#elif defined(__APPLE__)

    // From Apple's Technical Q&A QA1361 (https://developer.apple.com/library/mac/qa/qa1361/_index.html)
    // We simply ask the kernel if we are being debugged.
    #ifndef __APPLE_API_UNSTABLE
        #define __APPLE_API_UNSTABLE
    #endif
    #include <unistd.h>
    #include <sys/sysctl.h>

    namespace Sys {
        bool IsDebuggerAttached() {
            int mib[4] = {
                CTL_KERN,
                KERN_PROC,
                KERN_PROC_PID,
                getpid()
            };
            size_t size = sizeof(info);

            kinfo_proc info = {0};
            sysctl(mib, sizeof(mib) / sizeof(mib[0]), &info, &size, nullptr, 0);

            return info.kp_proc.p_flag & P_TRACED != 0;
        }
    }

#else
#error "Debugger.cpp unimplemented for this platform"
#endif
