#include "SADXModLoader.h"
#include <stdio.h>
#include "IniFile.hpp"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum KindofTextureDX { LikeDream, OriginalDX, DreamcastT, UekawaDX };
enum KindofTextureDC { OriginalDC, UekawaDC };
enum DXSuperS { LikeDreamSS, OriginalDXSS, DreamcastTSS, Upgraded };
enum DCSuperS { OriginalDCSS, UpgradedDC };

static int KindofTextDX = LikeDream;
static int KindofTextDC = OriginalDC;
static int DCSS = UpgradedDC;
static int DXSS = Upgraded;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Functions
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");
		std::string KindofTextDX_String = "LikeDream";
		KindofTextDX_String = config->getString("Textures", "DXChars", "LikeDream");
		std::string DXSS_String = "Upgraded";
		DXSS_String = config->getString("Textures", "DXSS", "Upgraded");
		std::string KindofTextDC_String = "OriginalDC";
		KindofTextDC_String = config->getString("Textures", "DreamcastChars", "OriginalDC");
		std::string DCSS_String = "UpgradedDC";
		DCSS_String = config->getString("Textures", "DreamcastSS", "OriginalDCSS");
		if (KindofTextDX_String == "LikeDream") KindofTextDX = LikeDream;
		if (KindofTextDX_String == "DreamcastT") KindofTextDX = DreamcastT;
		if (KindofTextDX_String == "OriginalDX") KindofTextDX = OriginalDX;
		if (KindofTextDX_String == "UekawaDX") KindofTextDX = UekawaDX;
		if (KindofTextDC_String == "OriginalDC") KindofTextDC = OriginalDC;
		if (KindofTextDC_String == "UekawaDC") KindofTextDC = UekawaDC;
		if (DXSS_String == "Upgraded") DXSS = Upgraded;
		if (DXSS_String == "LikeDreamSS") DXSS = LikeDreamSS;
		if (DXSS_String == "DreamcastTSS") DXSS = DreamcastTSS;
		if (DXSS_String == "OriginalDXSS") DXSS = OriginalDXSS;
		if (DCSS_String == "OriginalDCSS") DCSS = OriginalDCSS;
		if (DCSS_String == "UpgradedDC") DCSS = UpgradedDC;
		HMODULE AIHD = GetModuleHandle(L"AI_char_text");
		HMODULE DCcharacters = GetModuleHandle(L"SA1_Chars");
		
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

			if (DXSS == Upgraded)
			{
				ReplacePVM("supersonic", "supersonic_n")
			}

			if (DXSS == DreamcastTSS)
			{
				ReplacePVM("supersonic", "supersonic_dxd")
			}

			if (DXSS == LikeDreamSS)
			{
				ReplacePVM("supersonic", "supersonic_ld")
			}

			if (DCcharacters)
			{
				if (KindofTextDC == UekawaDC)
				{
					ReplacePVM("amy", "AMY_DCu");
					ReplacePVM("big", "BIG_DCu");
					ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dcu");
					ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dcu");
					ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dcu");
					ReplacePVM("knuckles", "knuckles_dcu");
					ReplacePVM("m_head_1", "m_head_1_dcu");
					ReplacePVM("m_tr_p", "m_tr_p_dcu");
					ReplacePVM("Miles", "Miles_DCu");
					ReplacePVM("shooting1", "shooting1_dcu");
					ReplacePVM("shooting2", "shooting2_dcu");
					ReplacePVM("SONIC", "SONIC_DCu");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("amy", "AMY_DC");
					ReplacePVM("big", "BIG_DC");
					ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dc");
					ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dc");
					ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dc");
					ReplacePVM("knuckles", "knuckles_dc");
					ReplacePVM("m_head_1", "m_head_1_dc");
					ReplacePVM("m_tr_p", "m_tr_p_dc");
					ReplacePVM("Miles", "Miles_DC");
					ReplacePVM("shooting1", "shooting1_dc");
					ReplacePVM("shooting2", "shooting2_dc");
					ReplacePVM("SONIC", "SONIC_DC");
				}

				if (DCSS == UpgradedDC)
				{
					ReplacePVM("supersonic", "supersonic_dcn")
				}

				if (DCSS == OriginalDCSS)
				{
					ReplacePVM("supersonic", "supersonic_dc")
				}
			}
		

	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}