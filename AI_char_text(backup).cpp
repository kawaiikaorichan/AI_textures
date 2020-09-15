#include "SADXModLoader.h"
#include <stdio.h>
#include "IniFile.hpp"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum KindofTextureDC { OriginalDC, UekawaDC };
enum KindofTextureDX { LikeDream, OriginalDX, DreamcastT, UekawaDX };
enum DCSuperS { OriginalDCSS, UpgradedDC };
enum DXSuperS { LikeDreamSS, OriginalDXSS, DreamcastTSS, UpgradedDX };

static int KindofTextDC = OriginalDC;
static int KindofTextDX = LikeDream;
static int DCSS = UpgradedDC;
static int DXSS = UpgradedDX;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Functions
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		std::string KindofTextDC_String = "OriginalDC";
		KindofTextDC_String = config->getString("Textures", "DreamcastChars", "OriginalDC");
		std::string KindofTextDX_String = "LikeDream";
		KindofTextDX_String = config->getString("Textures", "DXChars", "LikeDream");
		std::string DCSS_String = "UpgradedDC";
		DCSS_String = config->getString("Textures", "DreamcastSS", "OriginalDCSS");
		std::string DXSS_String = "UpgradedDX";
		DXSS_String = config->getString("Textures", "DXSS", "OriginalDXSS");
		if (KindofTextDC_String == "OriginalDC") KindofTextDC = OriginalDC;
		if (KindofTextDC_String == "UekawaDC") KindofTextDC = UekawaDC;
		if (KindofTextDX_String == "LikeDream") KindofTextDX = LikeDream;
		if (KindofTextDX_String == "DreamcastT") KindofTextDX = DreamcastT;
		if (KindofTextDX_String == "OriginalDX") KindofTextDX = OriginalDX;
		if (KindofTextDX_String == "UekawaDX") KindofTextDX = UekawaDX;
		if (DCSS_String == "OriginalDCSS") DCSS = OriginalDCSS;
		if (DCSS_String == "UpgradedDC") DCSS = UpgradedDC;
		if (DXSS_String == "LikeDreamSS") DCSS = LikeDreamSS;
		if (DXSS_String == "DreamcastTSS") DCSS = DreamcastTSS;
		if (DXSS_String == "OriginalDXSS") DCSS = OriginalDXSS;
		if (DXSS_String == "UpgradedDX") DCSS = UpgradedDX;
		

		if (KindofTextDC == UekawaDC)
		{
			ReplacePVM("amy_dc", "AMY_DCu");
			ReplacePVM("big_dc", "BIG_DCu");
			ReplacePVM("ev_tr1_with_sonic_dc", "ev_tr1_with_sonic_dcu");
			ReplacePVM("ev_tr2before_with_sonic_dc", "ev_tr2before_with_sonic_dcu");
			ReplacePVM("ev_tr2change_with_sonic_dc", "ev_tr2change_with_sonic_dcu");
			ReplacePVM("knuckles_dc", "knuckles_dcu");
			ReplacePVM("m_head_1_dc", "m_head_1_dcu");
			ReplacePVM("m_tr_p_dc", "m_tr_p_dcu");
			ReplacePVM("Miles_dc", "Miles_DCu");
			ReplacePVM("shooting1_dc", "shooting1_dcu");
			ReplacePVM("shooting2_dc", "shooting2_dcu");
			ReplacePVM("SONIC_dc", "SONIC_DCu");
		}

		if (KindofTextDX == LikeDream)
		{
			ReplacePVM("amy", "amy_ld");
			ReplacePVM("big", "big_ld");
			ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_ld");
			ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_ld");
			ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_ld");
			ReplacePVM("knuckles", "knuckles_ld");
			ReplacePVM("m_head_1", "m_head_1_ld");
			ReplacePVM("m_tr_p", "m_tr_p_ld");
			ReplacePVM("metalsonic", "metalsonic_ld");
			ReplacePVM("Miles", "Miles_ld");
			ReplacePVM("shooting1", "shooting1_ld");
			ReplacePVM("shooting2", "shooting2_ld");
			ReplacePVM("sonic", "sonic_ld");
		}

		if (KindofTextDX == DreamcastT)
		{
			ReplacePVM("amy", "AMY_dxd");
			ReplacePVM("big", "BIG_dxd");
			ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dxd");
			ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dxd");
			ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dxd");
			ReplacePVM("knuckles", "knuckles_dxd");
			ReplacePVM("m_head_1", "m_head_1_dxd");
			ReplacePVM("m_tr_p", "m_tr_p_dxd");
			ReplacePVM("metalsonic", "metalsonic_dxd");
			ReplacePVM("Miles", "Miles_dxd");
			ReplacePVM("shooting1", "shooting1_dxd");
			ReplacePVM("shooting2", "shooting2_dxd");
			ReplacePVM("SONIC", "SONIC_dxd");
		}


		if (KindofTextDX == UekawaDX)
		{
			ReplacePVM("amy", "AMY_dxu");
			ReplacePVM("big", "BIG_dxu");
			ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dxu");
			ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dxu");
			ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dxu");
			ReplacePVM("knuckles", "knuckles_dxu");
			ReplacePVM("m_head_1", "m_head_1_dxu");
			ReplacePVM("m_tr_p", "m_tr_p_dxu");
			ReplacePVM("metalsonic", "metalsonic_dxu");
			ReplacePVM("Miles", "Miles_dxu");
			ReplacePVM("shooting1", "shooting1_dxu");
			ReplacePVM("shooting2", "shooting2_dxu");
			ReplacePVM("SONIC", "SONIC_dxu");
		}

		if (DCSS == UpgradedDC)
		{
			ReplacePVM("supersonic_dc", "supersonic_dcn")
		}

		if (DXSS == UpgradedDX)
		{
			ReplacePVM("supersonic", "supersonic_dxn")
		}

		if (DXSS == DreamcastTSS)
		{
			ReplacePVM("supersonic", "supersonic_dxd")
		}

		if (DXSS == LikeDreamSS)
		{
			ReplacePVM("supersonic", "supersonic_ld")
		}

	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}