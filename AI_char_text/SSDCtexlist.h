DataArray(NJS_TEXLIST, SSArua01, 0x01422160, 8); //0xC0
DataArray(NJS_TEXLIST, SSArua02, 0x014221A0, 8); //0x120
DataArray(NJS_TEXLIST, SSSplash, 0x014221E0, 8); //0x180
DataArray(NJS_TEXLIST, SSHoming, 0x01422228, 49); //0x24C

NJS_TEXNAME SUPERSONIC_DCTexName[] = {
	{ (void*)"s_anakage1" },
	{ (void*)"s_hando2" },
	{ (void*)"s_testhand" },
	{ (void*)"alltx_dwhite" },
	{ (void*)"stx_eye00" },
	{ (void*)"stx_hanasaki" },
	{ (void*)"stx_hoho" },
	{ (void*)"stx_itemshoos0" },
	{ (void*)"stx_itemshoos1" },
	{ (void*)"stx_shoose16" },
	{ (void*)"stx_shoose17" },
	{ (void*)"stx_shoose18" },
	{ (void*)"stx_shoose19" },
	{ (void*)"sstx_body" },
	{ (void*)"sstx_redeye" },
	{ (void*)"sstx_spin" },
	{ (void*)"s1sonic01" }, //16th entry (0x0C0)
	{ (void*)"s1sonic02" },
	{ (void*)"s1sonic03" },
	{ (void*)"s1sonic04" },
	{ (void*)"s1sonic05" },
	{ (void*)"s1sonic06" },
	{ (void*)"s1sonic07" },
	{ (void*)"s1sonic08" },
	{ (void*)"s2sonic01" }, //24th entry (0x120)
	{ (void*)"s2sonic02" },
	{ (void*)"s2sonic03" },
	{ (void*)"s2sonic04" },
	{ (void*)"s2sonic05" },
	{ (void*)"s2sonic06" },
	{ (void*)"s2sonic07" },
	{ (void*)"s2sonic08" },
	{ (void*)"ss_waterl01" }, //32nd entry (0x180)
	{ (void*)"ss_waterl02" },
	{ (void*)"ss_waterl03" },
	{ (void*)"ss_waterl04" },
	{ (void*)"ss_waterl05" },
	{ (void*)"ss_waterl06" },
	{ (void*)"ss_waterl07" },
	{ (void*)"ss_waterl08" },
	{ (void*)"ss_waterl09" },
	{ (void*)"ss_waterl10" },
	{ (void*)"ss_waterl11" },
	{ (void*)"ss_waterl12" },
	{ (void*)"ss_waterl13" },
	{ (void*)"ss_waterl14" },
	{ (void*)"ss_waterl15" },
	{ (void*)"ss_waterl16" },
	{ (void*)"ss_ball_a" },
	{ (void*)"ss_ball_b" }, //49th entry (0x24C)
	{ (void*)"ss_dash01" }, //50 0x258
	{ (void*)"ss_dash02" }, //51 0x264
	{ (void*)"ss_dash03" }, //52 0x270
	{ (void*)"ss_dash04" }, //53 0x27C
	{ (void*)"ss_dash05" }, //54 0x288
	{ (void*)"ss_dash06" }, //55 0x294
	{ (void*)"ss_dash07" }, //56 0x2A0
	{ (void*)"ss_dash08" }, //57 0x2AC
	{ (void*)"ss_dash09" }, //58 0x2B8
	{ (void*)"ss_dash10" }, //59 0x2C4
	{ (void*)"ss_dash11" }, //60 0x2D0
	{ (void*)"ss_dash12" }, //61 0x2DC
	{ (void*)"ss_dash13" }, //62 0x2E8
	{ (void*)"ss_dash14" }, //63 0x2F4
	{ (void*)"ss_dash15" }, //64 0x300
	{ (void*)"ss_dash16" }, //65 0x30C
	{ (void*)"ss_dash17" }, //66 0x318
	{ (void*)"ss_dash18" }, //67 0x324
	{ (void*)"ss_dash19" }, //68 0x330
	{ (void*)"ss_dash20" }, //69 0x33C
	{ (void*)"ss_dash21" }, //70 0x348
	{ (void*)"ss_dash22" }, //71 0x354
	{ (void*)"ss_dash23" }, //72 0x360
	{ (void*)"stx_kanagu" },
	{ (void*)"stx_kutusoko0" },
	{ (void*)"stx_kutusoko1" },
	{ (void*)"stx_shoose4" },
	{ (void*)"stx_shoose6" },
	{ (void*)"stx_itemring" },
	{ (void*)"sstx_upgspin" },
	{ (void*)"0" },
	{ (void*)"1" },
	{ (void*)"2" },
	{ (void*)"3" },
	{ (void*)"4" },
	{ (void*)"5" },
	{ (void*)"6" },
	{ (void*)"7" },
	{ (void*)"8" },
	{ (void*)"9" },
	{ (void*)"10" },
	{ (void*)"11" },
	{ (void*)"12" },
	{ (void*)"13" },
	{ (void*)"14" },
	{ (void*)"15"}
};

NJS_TEXLIST SS_PVM = { arrayptrandlength(SUPERSONIC_DCTexName) };

NJS_TEXLIST SSAura01[] = {
	{ &SUPERSONIC_DCTexName[16], 1 },
	{ &SUPERSONIC_DCTexName[17], 1 },
	{ &SUPERSONIC_DCTexName[18], 1 },
	{ &SUPERSONIC_DCTexName[19], 1 },
	{ &SUPERSONIC_DCTexName[20], 1 },
	{ &SUPERSONIC_DCTexName[21], 1 },
	{ &SUPERSONIC_DCTexName[22], 1 },
	{ &SUPERSONIC_DCTexName[23], 1 }
};

NJS_TEXLIST SSAura02[] = {
	{ &SUPERSONIC_DCTexName[24], 1 },
	{ &SUPERSONIC_DCTexName[25], 1 },
	{ &SUPERSONIC_DCTexName[26], 1 },
	{ &SUPERSONIC_DCTexName[27], 1 },
	{ &SUPERSONIC_DCTexName[28], 1 },
	{ &SUPERSONIC_DCTexName[29], 1 },
	{ &SUPERSONIC_DCTexName[30], 1 },
	{ &SUPERSONIC_DCTexName[31], 1 }
};

NJS_TEXLIST SSWaterThing[] = {
	{ &SUPERSONIC_DCTexName[32], 2 },
	{ &SUPERSONIC_DCTexName[34], 2 },
	{ &SUPERSONIC_DCTexName[36], 2 },
	{ &SUPERSONIC_DCTexName[38], 2 },
	{ &SUPERSONIC_DCTexName[40], 2 },
	{ &SUPERSONIC_DCTexName[42], 2 },
	{ &SUPERSONIC_DCTexName[44], 2 },
	{ &SUPERSONIC_DCTexName[46], 2 }
};

NJS_TEXLIST SSHomingTex1[] = {
	{ &SUPERSONIC_DCTexName[48], 1 }
};

NJS_TEXLIST SSHomingTex2[] = {
	{ &SUPERSONIC_DCTexName[49], 1 },
	{ &SUPERSONIC_DCTexName[50], 1 },
	{ &SUPERSONIC_DCTexName[51], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[52], 1 },
	{ &SUPERSONIC_DCTexName[53], 1 },
	{ &SUPERSONIC_DCTexName[54], 1 },
	{ &SUPERSONIC_DCTexName[55], 1 },
	{ &SUPERSONIC_DCTexName[56], 1 },
	{ &SUPERSONIC_DCTexName[57], 1 },
	{ &SUPERSONIC_DCTexName[58], 1 },
	{ &SUPERSONIC_DCTexName[59], 1 },
	{ &SUPERSONIC_DCTexName[60], 1 }
};

NJS_TEXLIST SSHomingTex3[] = {
	{ &SUPERSONIC_DCTexName[61], 1 },
	{ &SUPERSONIC_DCTexName[50], 1 },
	{ &SUPERSONIC_DCTexName[62], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[63], 1 },
	{ &SUPERSONIC_DCTexName[64], 1 },
	{ &SUPERSONIC_DCTexName[65], 1 },
	{ &SUPERSONIC_DCTexName[66], 1 },
	{ &SUPERSONIC_DCTexName[67], 1 },
	{ &SUPERSONIC_DCTexName[68], 1 },
	{ &SUPERSONIC_DCTexName[69], 1 },
	{ &SUPERSONIC_DCTexName[70], 1 },
	{ &SUPERSONIC_DCTexName[71], 1 },
	{ &SUPERSONIC_DCTexName[72], 1 }
};

NJS_MATERIAL matlist_8D6D5997198645A8A53[] = {
	{ { 0xFFB2B2B2 }, { 0xFFFFFFFF }, 11, 78, NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_USE_TEXTURE | NJD_FLAG_USE_ENV | NJD_FLAG_IGNORE_LIGHT | NJD_DA_INV_SRC | NJD_SA_SRC },
	{ { 0xFFB2B2B2 }, { 0xFF808080 }, 11, 6, NJD_FLAG_CLAMP_V | NJD_FLAG_CLAMP_U | NJD_FLAG_IGNORE_SPECULAR | NJD_FLAG_USE_TEXTURE | NJD_DA_INV_SRC | NJD_SA_SRC }
};