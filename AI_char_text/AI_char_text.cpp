#include "pch.h"
#include "IniFile.hpp"
#include "SSDCtexlist.h"

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

int SUPERSONICGlowtextures[] = { 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90 }; //Textures IDs

//Options
enum KindofTextureDX { LikeDream, OriginalDX, DreamcastT };
enum KindofTextureDC { OriginalDC, LikeDX };
enum KindofTextureGamma { OriginalG, Reworked };
enum DXSuperS { LikeDreamSS, OriginalDXSS, DreamcastTSS, Combined, Upgraded, UpgradedDX, Solo, SoloDX, SoloComb };
enum DCSuperS { OriginalDCSS, LikeDXSS, UpgradedDC, UpgradedLDX, SoloDC, SoloLDX };
enum Mural { Vanilla, Preview };

static bool EnableSonic = true;
static bool EnableSSonic = true;
static bool EnableTails = true;
static bool EnableKnuckles = true;
static bool EnableAmy = true;
static bool EnableGamma = true;
static bool EnableBig = true;
static bool EnableMetal = true;
static int KindofTextDX = LikeDream;
static int KindofTextDC = OriginalDC;
static int KindofTextGamma = Reworked;
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
		EnableSSonic = config->getBool("Characters", "EnableSSonic", true);
		EnableTails = config->getBool("Characters", "EnableTails", true);
		EnableKnuckles = config->getBool("Characters", "EnableKnuckles", true);
		EnableAmy = config->getBool("Characters", "EnableAmy", true);
		EnableGamma = config->getBool("Characters", "EnableGamma", true);
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
		DCSS_String = config->getString("Textures", "DreamcastSS", "UpgradedDC");
		std::string KindofTextGamma_String = "Reworked";
		KindofTextGamma_String = config->getString("Textures", "Gamma", "Reworked");
		std::string LWMural_String = "Vanilla";
		LWMural_String = config->getString("Misc", "Mural", "Vanilla");

		if (KindofTextDX_String == "LikeDream") KindofTextDX = LikeDream;
		if (KindofTextDX_String == "DreamcastT") KindofTextDX = DreamcastT;
		if (KindofTextDX_String == "OriginalDX") KindofTextDX = OriginalDX;
		if (KindofTextDC_String == "OriginalDC") KindofTextDC = OriginalDC;
		if (KindofTextDC_String == "LikeDX") KindofTextDC = LikeDX;
		if (KindofTextGamma_String == "OriginalG") KindofTextGamma = OriginalG;
		if (KindofTextGamma_String == "Reworked") KindofTextGamma = Reworked;
		if (DXSS_String == "Upgraded") DXSS = Upgraded;
		if (DXSS_String == "LikeDreamSS") DXSS = LikeDreamSS;
		if (DXSS_String == "DreamcastTSS") DXSS = DreamcastTSS;
		if (DXSS_String == "OriginalDXSS") DXSS = OriginalDXSS;
		if (DXSS_String == "Combined") DXSS = Combined;
		if (DXSS_String == "UpgradedDX") DXSS = UpgradedDX;
		if (DXSS_String == "Solo") DXSS = Solo;
		if (DXSS_String == "SoloDX") DXSS = SoloDX;
		if (DXSS_String == "SoloComb") DXSS = SoloComb;
		if (DCSS_String == "OriginalDCSS") DCSS = OriginalDCSS;
		if (DCSS_String == "LikeDXSS") DCSS = LikeDXSS;
		if (DCSS_String == "UpgradedDC") DCSS = UpgradedDC;
		if (DCSS_String == "UpgradedLDX") DCSS = UpgradedLDX;
		if (DCSS_String == "SoloDC") DCSS = SoloDC;
		if (DCSS_String == "SoloLDX") DCSS = SoloLDX;
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
			}
		}

		if (EnableSSonic)
		{
			WriteData((NJS_TEXLIST**)0x55E65C, SSAura01);
			WriteData((NJS_TEXLIST**)0x55E751, SSAura01);
			WriteData((NJS_TEXLIST**)0x55E712, SSAura02);
			WriteData((NJS_TEXLIST**)0x55E7CD, SSWaterThing);
			WriteData((NJS_TEXLIST**)0x55F2B3, SSHomingTex1);
			WriteData((NJS_TEXLIST**)0x55F1D1, SSHomingTex1);
			WriteData((NJS_TEXLIST**)0x55F1DC, SSHomingTex2);
			WriteData((NJS_TEXLIST**)0x55F2BE, SSHomingTex2);
			WriteData((NJS_TEXLIST**)0x55F677, SSHomingTex2);
			WriteData((NJS_TEXLIST**)0x55F669, SSHomingTex3);
			SUPERSONIC_TEXLIST = SS_PVM;

			if (DXSS == Upgraded)
			{
				ReplacePVM("supersonic", "supersonic_n");
				ReplacePVM("hypersonic", "hypersonic_n");
				ReplacePVM("hypersonic_g", "hypersonic_n");
				ReplacePVM("DXR_HYPER", "hypersonic_n");
			}

			if (DXSS == UpgradedDX)
			{
				ReplacePVM("supersonic", "supersonic_ndx");
				ReplacePVM("hypersonic", "hypersonic_ndx");
				ReplacePVM("hypersonic_g", "hypersonic_ndx");
				ReplacePVM("DXR_HYPER", "hypersonic_ndx");
			}

			if (DXSS == DreamcastTSS)
			{
				ReplacePVM("supersonic", "supersonic_dxd");
				ReplacePVM("hypersonic", "hypersonic_dxd");
				ReplacePVM("hypersonic_g", "hypersonic_dxd");
				ReplacePVM("DXR_HYPER", "hypersonic_dxd");
			}

			if (DXSS == LikeDreamSS)
			{
				ReplacePVM("supersonic", "supersonic_ld");
				ReplacePVM("hypersonic", "hypersonic_ld");
				ReplacePVM("hypersonic_g", "hypersonic_ld");
				ReplacePVM("DXR_HYPER", "hypersonic_ld");
			}

			if (DXSS == OriginalDXSS)
			{
				ReplacePVM("supersonic", "supersonic_dx");
				ReplacePVM("hypersonic", "hypersonic_dx");
				ReplacePVM("hypersonic_g", "hypersonic_dx");
				ReplacePVM("DXR_HYPER", "hypersonic_dx");
			}

			if (DXSS == Combined)
			{
				ReplacePVM("supersonic", "supersonic_comb");
				ReplacePVM("hypersonic", "hypersonic_dx");
				ReplacePVM("hypersonic_g", "hypersonic_dx");
				ReplacePVM("DXR_HYPER", "hypersonic_dx");
			}

			if (DXSS == Solo)
			{
				ReplacePVM("supersonic", "supersonic_solo");
				ReplacePVM("hypersonic", "hypersonic_solo");
				ReplacePVM("hypersonic_g", "hypersonic_solo");
				ReplacePVM("DXR_HYPER", "hypersonic_solo");
			}

			if (DXSS == SoloDX)
			{
				ReplacePVM("supersonic", "supersonic_solodx");
				ReplacePVM("hypersonic", "hypersonic_solodx");
				ReplacePVM("hypersonic_g", "hypersonic_solodx");
				ReplacePVM("DXR_HYPER", "hypersonic_solodx");
			}

			if (DXSS == SoloComb)
			{
				ReplacePVM("supersonic", "supersonic_solocomb");
				ReplacePVM("hypersonic", "hypersonic_solodx");
				ReplacePVM("hypersonic_g", "hypersonic_solodx");
				ReplacePVM("DXR_HYPER", "hypersonic_solodx");
			}

			if (DCcharacters)
			{
				if (DCSS == UpgradedDC)
				{
					ReplacePVM("supersonic", "supersonic_dcn");
					ReplacePVM("supersonic_dc_a", "supersonic_dcn");
					ReplacePVM("hypersonic_dc", "hypersonic_dcn");
					ReplacePVM("hypersonic_dc_a", "hypersonic_dcn");
					ReplacePVM("HYPERSONIC_G_DC", "hypersonic_dcn");
					ReplacePVM("HYPERSONIC_V_DC", "hypersonic_dcn");
					ReplacePVM("HYPERSONIC_V_P_DC", "hypersonic_dcn");
				}

				if (DCSS == UpgradedLDX)
				{
					ReplacePVM("supersonic", "supersonic_dcndx");
					ReplacePVM("supersonic_dc_a", "supersonic_dcndx");
					ReplacePVM("hypersonic_dc", "hypersonic_dcndx");
					ReplacePVM("hypersonic_dc_a", "hypersonic_dcndx");
					ReplacePVM("HYPERSONIC_G_DC", "hypersonic_dcndx");
					ReplacePVM("HYPERSONIC_V_DC", "hypersonic_dcndx");
					ReplacePVM("HYPERSONIC_V_P_DC", "hypersonic_dcndx");
				}

				if (DCSS == LikeDXSS)
				{
					ReplacePVM("supersonic", "supersonic_ldx");
					ReplacePVM("supersonic_dc_a", "supersonic_ldx");
					ReplacePVM("hypersonic_dc", "hypersonic_ldx");
					ReplacePVM("hypersonic_dc_a", "hypersonic_ldx");
					ReplacePVM("HYPERSONIC_G_DC", "hypersonic_ldx");
					ReplacePVM("HYPERSONIC_V_DC", "hypersonic_ldx");
					ReplacePVM("HYPERSONIC_V_P_DC", "hypersonic_ldx");
				}

				if (DCSS == SoloDC)
				{
					ReplacePVM("supersonic", "supersonic_solodc");
					ReplacePVM("supersonic_dc_a", "supersonic_solodc");
					ReplacePVM("hypersonic_dc", "hypersonic_solodc");
					ReplacePVM("hypersonic_dc_a", "hypersonic_solodc");
					ReplacePVM("HYPERSONIC_G_DC", "hypersonic_solodc");
					ReplacePVM("HYPERSONIC_V_DC", "hypersonic_solodc");
					ReplacePVM("HYPERSONIC_V_P_DC", "hypersonic_solodc");
				}

				if (DCSS == SoloLDX)
				{
					ReplacePVM("supersonic", "supersonic_solodcdx");
					ReplacePVM("supersonic_dc_a", "supersonic_solodcdx");
					ReplacePVM("hypersonic_dc", "hypersonic_solodcdx");
					ReplacePVM("hypersonic_dc_a", "hypersonic_solodcdx");
					ReplacePVM("HYPERSONIC_G_DC", "hypersonic_solodcdx");
					ReplacePVM("HYPERSONIC_V_DC", "hypersonic_solodcdx");
					ReplacePVM("HYPERSONIC_V_P_DC", "hypersonic_solodcdx");
				}

				if (DCSS == OriginalDCSS)
				{
					ReplacePVM("supersonic", "supersonic_dc");
					//Solo, what the heck did you do for the next two not to work?
					ReplacePVM("supersonic_dc_a", "supersonic_dc");
					ReplacePVM("hypersonic_dc_a", "hypersonic_dc");
					ReplacePVM("HYPERSONIC_G_DC", "hypersonic_dc");
					ReplacePVM("HYPERSONIC_V_DC", "hypersonic_dc");
					ReplacePVM("HYPERSONIC_V_P_DC", "hypersonic_dc");
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

		if (EnableGamma)
		{
			if (KindofTextGamma == OriginalG)
			{
				ReplacePVM("E102", "E102_or");
			}

			if (KindofTextGamma == Reworked)
			{
				ReplacePVM("E102", "E102_r");
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
	}

	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer };
}