#include "pch.h"
#include "IniFile.hpp"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum KindofTextureDX { LikeDream, OriginalDX, DreamcastT };
enum KindofTextureDC { OriginalDC, LikeDX };
enum DXSuperS { LikeDreamSS, OriginalDXSS, DreamcastTSS, Upgraded };
enum DCSuperS { OriginalDCSS, LikeDXSS, UpgradedDC };
enum Mural { Vanilla, Preview };

static bool EnableSonic = true;
static bool EnableTails = true;
static bool EnableKnuckles = true;
static bool EnableAmy = true;
static bool EnableBig = true;
static bool EnableMetal = true;
static int KindofTextDX = LikeDream;
static int KindofTextDC = OriginalDC;
static int DCSS = UpgradedDC;
static int DXSS = Upgraded;
static int LWMural = Vanilla;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		const IniFile* config = new IniFile(std::string(path) + "\\config.ini");

		//Enabling or disabling HD textures
		EnableSonic = config->getBool("Characters", "EnableSonic", true);
		EnableTails = config->getBool("Characters", "EnableTails", true);
		EnableKnuckles = config->getBool("Characters", "EnableKnuckles", true);
		EnableAmy = config->getBool("Characters", "EnableAmy", true);
		EnableBig = config->getBool("Characters", "EnableBig", true);
		EnableMetal = config->getBool("Characters", "EnableMetal", true);

		//Choosing kind of textures
		std::string KindofTextDX_String = "LikeDream";
		KindofTextDX_String = config->getString("Textures", "DXChars", "LikeDream");
		std::string DXSS_String = "Upgraded";
		DXSS_String = config->getString("Textures", "DXSS", "Upgraded");
		std::string KindofTextDC_String = "OriginalDC";
		KindofTextDC_String = config->getString("Textures", "DreamcastChars", "OriginalDC");
		std::string DCSS_String = "UpgradedDC";
		DCSS_String = config->getString("Textures", "DreamcastSS", "OriginalDCSS");
		std::string LWMural_String = "Vanilla";
		LWMural_String = config->getString("Misc", "Mural", "Vanilla");

		if (KindofTextDX_String == "LikeDream") KindofTextDX = LikeDream;
		if (KindofTextDX_String == "DreamcastT") KindofTextDX = DreamcastT;
		if (KindofTextDX_String == "OriginalDX") KindofTextDX = OriginalDX;
		if (KindofTextDC_String == "OriginalDC") KindofTextDC = OriginalDC;
		if (KindofTextDC_String == "LikeDX") KindofTextDC = LikeDX;
		if (DXSS_String == "Upgraded") DXSS = Upgraded;
		if (DXSS_String == "LikeDreamSS") DXSS = LikeDreamSS;
		if (DXSS_String == "DreamcastTSS") DXSS = DreamcastTSS;
		if (DXSS_String == "OriginalDXSS") DXSS = OriginalDXSS;
		if (DCSS_String == "OriginalDCSS") DCSS = OriginalDCSS;
		if (DCSS_String == "LikeDXSS") DCSS = LikeDXSS;
		if (DCSS_String == "UpgradedDC") DCSS = UpgradedDC;
		if (LWMural_String == "Vanilla") LWMural = Vanilla;
		if (LWMural_String == "Preview") LWMural = Preview;

		//Compatiblity with other mods
		HMODULE DCcharacters = GetModuleHandle(L"SA1_Chars");
		HMODULE DCconversion = GetModuleHandle(L"DCMods_Main");
		HMODULE DXcharsR = GetModuleHandle(L"SADXR");
		HMODULE Hyper = GetModuleHandle(L"sadx-hyper-sonic");
		
		if (EnableSonic)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_ld");
				ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_ld");
				ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_ld");
				ReplacePVM("shooting1", "shooting1_ld");
				ReplacePVM("shooting2", "shooting2_ld");
				ReplacePVM("sonic", "sonic_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dxd");
				ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dxd");
				ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dxd");
				ReplacePVM("shooting1", "shooting1_dxd");
				ReplacePVM("shooting2", "shooting2_dxd");
				ReplacePVM("SONIC", "SONIC_dxd");
			}

			if (KindofTextDX == OriginalDX)
			{
				ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dx");
				ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dx");
				ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dx");
				ReplacePVM("shooting1", "shooting1_dx");
				ReplacePVM("shooting2", "shooting2_dx");
				ReplacePVM("sonic", "sonic_dx");
			}

			if (DXSS == Upgraded)
			{
				if (DXcharsR)
				{
					ReplacePVM("supersonic", "supersonic_nr");
				}
				else
				{
					ReplacePVM("supersonic", "supersonic_n");
				}
			}

			if (DXSS == DreamcastTSS)
			{
				if (DXcharsR)
				{
					ReplacePVM("supersonic", "supersonic_dxdr");
				}
				else
				{
					ReplacePVM("supersonic", "supersonic_dxd");
				}
			}

			if (DXSS == LikeDreamSS)
			{
				if (DXcharsR)
				{
					ReplacePVM("supersonic", "supersonic_ldr");
				}
				else
				{
					ReplacePVM("supersonic", "supersonic_ld");
				}
			}

			if (DXSS == OriginalDXSS)
			{
				if (DXcharsR)
				{
					ReplacePVM("supersonic", "supersonic_dxr");
				}
				else
				{
					ReplacePVM("supersonic", "supersonic_dx");
				}
			}


			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_ldx");
					ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_ldx");
					ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_ldx");
					ReplacePVM("shooting1", "shooting1_ldx");
					ReplacePVM("shooting2", "shooting2_ldx");
					ReplacePVM("SONIC", "SONIC_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dc");
					ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dc");
					ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dc");
					ReplacePVM("shooting1", "shooting1_dc");
					ReplacePVM("shooting2", "shooting2_dc");
					ReplacePVM("SONIC", "SONIC_DC");
				}

				if (DCSS == UpgradedDC)
				{
					ReplacePVM("supersonic", "supersonic_dcn");
				}

				if (DCSS == LikeDXSS)
				{
					ReplacePVM("supersonic", "supersonic_ldx");
				}

				if (DCSS == OriginalDCSS)
				{
					ReplacePVM("supersonic", "supersonic_dc");
				}
			}
		}

		if (EnableTails)
		{
			if (DXcharsR)
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("m_head_1", "m_head_1_ld");
					ReplacePVM("m_tr_p", "m_tr_p_ld");
					ReplacePVM("Miles", "Miles_ldr");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("m_head_1", "m_head_1_dxd");
					ReplacePVM("m_tr_p", "m_tr_p_dxd");
					ReplacePVM("Miles", "Miles_dxdr");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("m_head_1", "m_head_1_dx");
					ReplacePVM("m_tr_p", "m_tr_p_dx");
					ReplacePVM("Miles", "Miles_r");
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("m_head_1", "m_head_1_ld");
					ReplacePVM("m_tr_p", "m_tr_p_ld");
					ReplacePVM("Miles", "Miles_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("m_head_1", "m_head_1_dxd");
					ReplacePVM("m_tr_p", "m_tr_p_dxd");
					ReplacePVM("Miles", "Miles_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("m_head_1", "m_head_1_dx");
					ReplacePVM("m_tr_p", "m_tr_p_dx");
					ReplacePVM("Miles", "Miles_dx");
				}
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("m_head_1", "m_head_1_ldx");
					ReplacePVM("m_tr_p", "m_tr_p_ldx");
					ReplacePVM("Miles", "Miles_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("m_head_1", "m_head_1_dc");
					ReplacePVM("m_tr_p", "m_tr_p_dc");
					ReplacePVM("Miles", "Miles_DC");
				}
			}
		}

		if (EnableKnuckles)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("Knuckles", "Knuckles_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("Knuckles", "Knuckles_dxd");
			}

			if (KindofTextDX == OriginalDX)
			{
				ReplacePVM("Knuckles", "Knuckles_dx");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Knuckles", "Knuckles_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Knuckles", "Knuckles_DC");
				}
			}
		}

		if (EnableAmy)
		{
			if (DXcharsR)
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Amy", "Amy_ldr");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Amy", "Amy_dxdr");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Amy", "Amy_r");
				}
			}
			else
			{
				if (KindofTextDX == LikeDream)
				{
					ReplacePVM("Amy", "Amy_ld");
				}

				if (KindofTextDX == DreamcastT)
				{
					ReplacePVM("Amy", "Amy_dxd");
				}

				if (KindofTextDX == OriginalDX)
				{
					ReplacePVM("Amy", "Amy_dx");
				}
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Amy", "Amy_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Amy", "Amy_DC");
				}
			}
		}

		if (EnableBig)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("Big", "Big_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("Big", "Big_dxd");
			}

			if (KindofTextDX == OriginalDX)
			{
				ReplacePVM("Big", "Big_dx");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Big", "Big_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Big", "Big_DC");
				}
			}
		}

		if (EnableMetal)
		{
			if (KindofTextDX == LikeDream)
			{
				ReplacePVM("Metalsonic", "Metalsonic_ld");
			}

			if (KindofTextDX == DreamcastT)
			{
				ReplacePVM("Metalsonic", "Metalsonic_dxd");
			}

			if (KindofTextDX == OriginalDX)
			{
				ReplacePVM("Metalsonic", "Metalsonic_dx");
			}

			if (DCcharacters)
			{
				if (KindofTextDC == LikeDX)
				{
					ReplacePVM("Metalsonic", "Metalsonic_ldx");
				}

				if (KindofTextDC == OriginalDC)
				{
					ReplacePVM("Metalsonic", "Metalsonic_DC");
				}
			}
		}

		if (DCconversion)
		{
			if (LWMural == Vanilla)
			{
				ReplacePVM("RUIN03", "RUIN03_DC");
			}

			if (LWMural == Preview)
			{
				ReplacePVM("RUIN03", "RUIN03_DCP");
			}
		}
		ReplacePVM("DXR_AMY_EFF", "AMY_EFF_DC");
		ReplacePVM("DXR_CREAM", "cream_dx");
		ReplacePVM("DXR_KNU_EFF", "KNU_EFF_HD");
		ReplacePVM("DXR_SON_EFF", "SON_EFF_DC");
		ReplacePVM("DXR_TIKAL", "tikal_dx");
		ReplacePVM("DXR_HYPER", "hypersonic_dxr");
	}
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}