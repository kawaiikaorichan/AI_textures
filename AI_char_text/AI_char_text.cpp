#include "SADXModLoader.h"
#include <stdio.h>
const char MyString[] = "Ass";

//Macros
#define ReplacePVM(a, b) helperFunctions.ReplaceFile("system\\" a ".PVM", "system\\" b ".PVM");

//Options
enum KindofTextDC { OriginalDC, UekawaDC };
enum KindofTextDX { OriginalDX, DreamcastT, DClike, UekawaDX };
enum DCSS { OriginalDCSS, UpgradedDC };
enum DXSS { OriginalDXSS, DreamcastTSS, DClikeSS, UpgradedDX };

static int KindofTextDC = OriginalDC;
static int KindofTextDX = OriginalDX;
static int DCSS = OriginalDCSS;
static int DXSS = OriginalDXSS;

extern "C"
{
	__declspec(dllexport) __declspec(dllexport) void __cdecl Init(const char* path, const HelperFunctions& helperFunctions)
	{
		//Functions
		if (KindofTextDC == OriginalDC)
		{
			ReplacePVM("amy_dc", "AMY_DCo");
			ReplacePVM("big_dc", "BIG_DCo");
			ReplacePVM("ev_tr1_with_sonic_dc", "ev_tr1_with_sonic_dco");
			ReplacePVM("ev_tr2before_with_sonic_dc", "ev_tr2before_with_sonic_dco");
			ReplacePVM("ev_tr2change_with_sonic_dc", "ev_tr2change_with_sonic_dco");
			ReplacePVM("knuckles_dc", "knuckles_dco");
			ReplacePVM("m_head_1_dc", "m_head_1_dco");
			ReplacePVM("m_tr_p_dc", "m_tr_p_dco");
			ReplacePVM("metalsonic_dc", "metalsonic_dco");
			ReplacePVM("Miles_dc", "Miles_DCo");
			ReplacePVM("shooting1_dc", "shooting1_dco");
			ReplacePVM("shooting2_dc", "shooting2_dco");
			ReplacePVM("SONIC_dc", "SONIC_DCo");
		}

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
			ReplacePVM("metalsonic_dc", "metalsonic_dcu");
			ReplacePVM("Miles_dc", "Miles_DCu");
			ReplacePVM("shooting1_dc", "shooting1_dcu");
			ReplacePVM("shooting2_dc", "shooting2_dcu");
			ReplacePVM("SONIC_dc", "SONIC_DCu");
		}

		if (KindofTextDX == OriginalDX)
		{
			ReplacePVM("amy", "AMY_dx");
			ReplacePVM("big", "BIG_dx");
			ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dx");
			ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dx");
			ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dx");
			ReplacePVM("knuckles", "knuckles_dx");
			ReplacePVM("m_head_1", "m_head_1_dx");
			ReplacePVM("m_tr_p", "m_tr_p_dx");
			ReplacePVM("metalsonic", "metalsonic_dx");
			ReplacePVM("Miles", "Miles_dx");
			ReplacePVM("shooting1", "shooting1_dx");
			ReplacePVM("shooting2", "shooting2_dx");
			ReplacePVM("SONIC", "SONIC_dx");
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


		if (KindofTextDX == DClike)
		{
			ReplacePVM("amy", "AMY_dxl");
			ReplacePVM("big", "BIG_dxl");
			ReplacePVM("ev_tr1_with_sonic", "ev_tr1_with_sonic_dxl");
			ReplacePVM("ev_tr2before_with_sonic", "ev_tr2before_with_sonic_dxl");
			ReplacePVM("ev_tr2change_with_sonic", "ev_tr2change_with_sonic_dxl");
			ReplacePVM("knuckles", "knuckles_dxl");
			ReplacePVM("m_head_1", "m_head_1_dxl");
			ReplacePVM("m_tr_p", "m_tr_p_dxl");
			ReplacePVM("metalsonic", "metalsonic_dxl");
			ReplacePVM("Miles", "Miles_dxl");
			ReplacePVM("shooting1", "shooting1_dxl");
			ReplacePVM("shooting2", "shooting2_dxl");
			ReplacePVM("SONIC", "SONIC_dxl");
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

		if (DCSS == OriginalDCSS)
		{
			ReplacePVM("supersonic_dc", "supersonic_dco")
		}

		if (DCSS == UpgradedDC)
		{
			ReplacePVM("supersonic_dc", "supersonic_dcn")
		}

		if (DXSS == OriginalDXSS)
		{
			ReplacePVM("supersonic", "supersonic_dx")
		}

		if (DXSS == DreamcastTSS)
		{
			ReplacePVM("supersonic", "supersonic_dxd")
		}

		if (DXSS == DClikeSS)
		{
			ReplacePVM("supersonic", "supersonic_dxl")
		}

		if (DXSS == UpgradedDX)
		{
			ReplacePVM("supersonic", "supersonic_dxn")
		}
	}
}