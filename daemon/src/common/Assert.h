/*
===========================================================================
Daemon BSD Source Code
Copyright (c) 2013-2014, Daemon Developers
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Daemon developers nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL DAEMON DEVELOPERS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
===========================================================================
*/

// TODO:
//  - Documentation
//  - __assume __builtin_unreachable

#ifndef COMMON_ASSERT_H_
#define COMMON_ASSERT_H_

#if defined(_MSC_VER)
    #define DAEMON_ASSERT_LOOP_CONDITION (0,0)
#else
    #define DAEMON_ASSERT_LOOP_CONDITION (0)
#endif

#if defined(DEBUG)
    #define DAEMON_ASSERT_CALLSITE_HELPER(file, func, line, code, condition, message) \
        do { \
            code; \
            if (!condition) { \
                std::string msg = Str::Format("Assertion failure at %s:%s (%s): %s", file, line, func, message); \
                if (Sys::IsDebuggerAttached()) { \
                    Log::Warn(msg); \
                    BREAKPOINT(); \
                } \
                Sys::Error(msg); \
            } \
        while(DAEMON_ASSERT_LOOP_CONDITION)
#else
    #define DAEMON_ASSERT_CALLSITE_HELPER(file, func, line, code, condition, message)
#endif

#define DAEMON_ASSERT_CALLSITE(code, condition, message) DAEMON_ASSERT_CALLSITE_HELPER(__FILE__, __func__, __LINE__, code, condition, message)

#define DAEMON_ASSERT(condition) DAEMON_ASSERT_CALLSITE( \
        , \
        (condition), \
        Str::Format("\"%s\" is false", #condition) \
    )

#define DAEMON_ASSERT_EQ(a, b) DAEMON_ASSERT_CALLSITE( \
        auto&& expected = (a); auto&& actual = (b), \
        expected == actual, \
        Str::Format("\"%s == %s\" expected: %s, actual: %s", #a, #b, expected, actual) \
    );
#define DAEMON_ASSERT_NQ(a, b) DAEMON_ASSERT_CALLSITE( \
        auto&& notExpected = (a); auto&& actual = (b), \
        notExpected != actual, \
        Str::Format("\"%s != %s\" not expected: %s, actual: %s", #a, #b, notExpected, actual) \
    );

#define DAEMON_ASSERT_LT(a, b) DAEMON_ASSERT_CALLSITE( \
        auto&& bound = (a); auto&& actual = (b), \
        bound < actual, \
        Str::Format("\"%s < %s\" bound: %s, actual: %s", #a, #b, a, b) \
    );
#define DAEMON_ASSERT_LE(a, b) DAEMON_ASSERT_CALLSITE( \
        auto&& bound = (a); auto&& actual = (b), \
        bound <= actual, \
        Str::Format("\"%s <= %s\" bound: %s, actual: %s", #a, #b, a, b) \
    );
#define DAEMON_ASSERT_GT(a, b) DAEMON_ASSERT_CALLSITE( \
        auto&& bound = (a); auto&& actual = (b), \
        bound > actual, \
        Str::Format("\"%s > %s\" bound: %s, actual: %s", #a, #b, a, b) \
    );
#define DAEMON_ASSERT_GE(a, b) DAEMON_ASSERT_CALLSITE( \
        auto&& bound = (a); auto&& actual = (b), \
        bound >= actual, \
        Str::Format("\"%s >= %s\" bound: %s, actual: %s", #a, #b, a, b) \
    );

#define ASSERT DAEMON_ASSERT
#define ASSERT_EQ DAEMON_ASSERT_EQ
#define ASSERT_NQ DAEMON_ASSERT_NQ
#define ASSERT_LT DAEMON_ASSERT_LT
#define ASSERT_LE DAEMON_ASSERT_LE
#define ASSERT_GT DAEMON_ASSERT_GT
#define ASSERT_GE DAEMON_ASSERT_GE

#endif // COMMON_ASEERT_H_
