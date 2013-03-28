code

equ memset                                -1
equ memcpy                                -2
equ memcmp                                -3
equ strncpy                               -4
equ sin                                   -5
equ cos                                   -6
equ asin                                  -7
equ tanf                                  -8
equ atanf                                 -9
equ atan2                                 -10
equ sqrt                                  -11
equ floor                                 -12
equ ceil                                  -13
equ exp                                   -14
equ trap_SyscallABIVersion                -256
equ trap_Print                            -257
equ trap_Error                            -258
equ trap_Milliseconds                     -259
equ trap_Cvar_Register                    -260
equ trap_Cvar_Update                      -261
equ trap_Cvar_Set                         -262
equ trap_Cvar_VariableStringBuffer        -263
equ trap_Cvar_LatchedVariableStringBuffer -264
equ trap_Cvar_VariableIntegerValue        -265
equ trap_Argc                             -266
equ trap_Argv                             -267
equ trap_Args                             -268
equ trap_LiteralArgs                      -269
equ trap_GetDemoState                     -270
equ trap_GetDemoPos                       -271
equ trap_FS_FOpenFile                     -272
equ trap_FS_Read                          -273
equ trap_FS_Write                         -274
equ trap_FS_FCloseFile                    -275
equ trap_FS_GetFileList                   -276
equ trap_FS_Delete                        -277
equ trap_SendConsoleCommand               -278
equ trap_AddCommand                       -279
equ trap_RemoveCommand                    -280
equ trap_SendClientCommand                -281
equ trap_UpdateScreen                     -282
equ trap_CM_LoadMap                       -283
equ trap_CM_NumInlineModels               -284
equ trap_CM_InlineModel                   -285
equ trap_CM_TempBoxModel                  -286
equ trap_CM_TempCapsuleModel              -287
equ trap_CM_PointContents                 -288
equ trap_CM_TransformedPointContents      -289
equ trap_CM_BoxTrace                      -290
equ trap_CM_TransformedBoxTrace           -291
equ trap_CM_CapsuleTrace                  -292
equ trap_CM_TransformedCapsuleTrace       -293
equ trap_CM_BiSphereTrace                 -294
equ trap_CM_TransformedBiSphereTrace      -295
equ trap_CM_MarkFragments                 -296
equ trap_R_ProjectDecal                   -297
equ trap_R_ClearDecals                    -298
equ trap_S_StartSound                     -299
equ trap_S_StartSoundVControl             -299
equ trap_S_StartSoundEx                   -300
equ trap_S_StartLocalSound                -301
equ trap_S_ClearLoopingSounds             -302
equ trap_S_ClearSounds                    -303
equ trap_S_AddLoopingSound                -304
equ trap_S_AddRealLoopingSound            -305
equ trap_S_StopLoopingSound               -306
equ trap_S_StopStreamingSound             -307
equ trap_S_UpdateEntityPosition           -308
equ trap_S_GetVoiceAmplitude              -309
equ trap_S_GetSoundLength                 -310
equ trap_S_GetCurrentSoundTime            -311
equ trap_S_Respatialize                   -312
equ trap_S_RegisterSound                  -313
equ trap_S_StartBackgroundTrack           -314
equ trap_S_FadeBackgroundTrack            -315
equ trap_S_StartStreamingSound            -316
equ trap_R_LoadWorldMap                   -317
equ trap_R_RegisterModel                  -318
equ trap_R_RegisterSkin                   -319
equ trap_R_GetSkinModel                   -320
equ trap_R_GetShaderFromModel             -321
equ trap_R_RegisterShader                 -322
equ trap_R_RegisterFont                   -323
equ trap_R_RegisterShaderNoMip            -324
equ trap_R_RegisterShaderLightAttenuation -325
equ trap_R_ClearScene                     -326
equ trap_R_AddRefEntityToScene            -327
equ trap_R_AddRefLightToScene             -328
equ trap_R_AddPolyToScene                 -329
equ trap_R_AddPolysToScene                -330
equ trap_R_AddPolyBufferToScene           -331
equ trap_R_AddLightToScene                -332
equ trap_R_AddAdditiveLightToScene        -333
equ trap_GS_FS_Seek                       -334
equ trap_R_AddCoronaToScene               -335
equ trap_R_SetFog                         -336
equ trap_R_SetGlobalFog                   -337
equ trap_R_RenderScene                    -338
equ trap_R_SaveViewParms                  -339
equ trap_R_RestoreViewParms               -340
equ trap_R_SetColor                       -341
equ trap_R_SetClipRegion                  -342
equ trap_R_DrawStretchPic                 -343
equ trap_R_DrawRotatedPic                 -344
equ trap_R_DrawStretchPicGradient         -345
equ trap_R_Add2dPolys                     -346
equ trap_R_ModelBounds                    -347
equ trap_R_LerpTag                        -348
equ trap_GetGlconfig                      -349
equ trap_GetGameState                     -350
equ trap_GetCurrentSnapshotNumber         -351
equ trap_GetSnapshot                      -352
equ trap_GetServerCommand                 -353
equ trap_GetCurrentCmdNumber              -354
equ trap_GetUserCmd                       -355
equ trap_SetUserCmdValue                  -356
equ trap_SetClientLerpOrigin              -357
equ trap_MemoryRemaining                  -358
equ trap_Key_IsDown                       -359
equ trap_Key_GetCatcher                   -360
equ trap_Key_SetCatcher                   -361
equ trap_Key_GetKey                       -362
equ trap_Key_GetOverstrikeMode            -363
equ trap_Key_SetOverstrikeMode            -364
equ trap_PC_AddGlobalDefine               -365
equ trap_PC_LoadSource                    -366
equ trap_PC_FreeSource                    -367
equ trap_PC_ReadToken                     -368
equ trap_PC_SourceFileAndLine             -369
equ trap_PC_UnReadToken                   -370
equ trap_S_StopBackgroundTrack            -371
equ trap_RealTime                         -372
equ trap_SnapVector                       -373
equ trap_CIN_PlayCinematic                -374
equ trap_CIN_StopCinematic                -375
equ trap_CIN_RunCinematic                 -376
equ trap_CIN_DrawCinematic                -377
equ trap_CIN_SetExtents                   -378
equ trap_R_RemapShader                    -379
equ trap_GetEntityToken                   -380
equ trap_UI_Popup                         -381
equ trap_UI_ClosePopup                    -382
equ trap_Key_GetBindingBuf                -383
equ trap_Key_SetBinding                   -384
equ trap_Parse_AddGlobalDefine            -385
equ trap_Parse_LoadSource                 -386
equ trap_Parse_FreeSource                 -387
equ trap_Parse_ReadToken                  -388
equ trap_Parse_SourceFileAndLine          -389
equ trap_Key_KeynumToStringBuf            -390
equ trap_S_FadeAllSound                   -391
equ trap_R_inPVS                          -392
equ trap_GetHunkData                      -393
equ trap_R_LoadDynamicShader              -394
equ trap_R_RenderToTexture                -395
equ trap_R_GetTextureId                   -396
equ trap_R_Finish                         -397
equ trap_GetDemoName                      -398
equ trap_R_LightForPoint                  -399
equ trap_S_SoundDuration                  -400
equ trap_R_RegisterAnimation              -401
equ trap_R_CheckSkeleton                  -402
equ trap_R_BuildSkeleton                  -403
equ trap_R_BlendSkeleton                  -404
equ trap_R_BoneIndex                      -405
equ trap_R_AnimNumFrames                  -406
equ trap_R_AnimFrameRate                  -407
equ trap_CompleteCallback                 -408
equ trap_RegisterButtonCommands           -409
equ trap_GetClipboardData                 -410
equ trap_QuoteString                      -411
equ trap_Gettext                          -412
equ trap_R_Glyph                          -413
equ trap_R_GlyphChar                      -414
equ trap_R_UnregisterFont                 -415
equ trap_Pgettext                         -416
equ trap_R_inPVVS                         -417
equ trap_Key_SetTeam                      -418
equ trap_GettextPlural                    -419
equ trap_RegisterVisTest                  -420
equ trap_AddVisTestToScene                -421
equ trap_CheckVisibility                  -422
equ trap_UnregisterVisTest                -423
equ trap_SetColorGrading                  -424
