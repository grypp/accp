/*
 * CAPSACCRuntimeConst.hxx
 *
 *  Created on: May 18, 2013
 *      Author: guray ozen
 */

#ifndef CAPSACCRUNTIMECONST_CXX_
#define CAPSACCRUNTIMECONST_CXX_

#include <iostream>

namespace accparser {
	namespace caps {

		static const std::string caps_ns = "hmpprt::";
		static const std::string caps_init = "extern \"C\" CDLT_API void * hmpprt_init()";
		static const std::string caps_fini = "extern \"C\" CDLT_API void * hmpprt_fini";

		static const std::string caps_grouplet = caps_ns + "Context::getInstance()->getGrouplet()->addSignature(";
		static const std::string caps_codelet_launch = "__hmppcg_call.launch";

		static const std::string grid_size_x = "setSizeX";
		static const std::string grid_size_y = "setSizeY";
		static const std::string block_size_x = "setBlockSizeX";
		static const std::string block_size_y = "setBlockSizeY";
		static const std::string addParameter = "addLocalParameter";

		static const std::string caps_devptr = "DevicePtr";

		static const std::string caps_fe_enter = "openacci_enter_region";
		static const std::string caps_fe_pushdata = "openacci_push_data";
		static const std::string caps_fe_call = "openacci_call";

		static const int CAPS_func_count = 19;
		static const std::string CAPS_Functions_List[] = { caps_ns + "gr_atidf()", caps_ns + "gr_atidx()", caps_ns + "gr_atidy()", caps_ns + "gr_btidf()", caps_ns + "gr_btidx()", caps_ns + "gr_btidy()", caps_ns + "gr_btnumf()", caps_ns + "gr_btnumx()", caps_ns + "gr_gbidf()", caps_ns + "gr_gbidx()", caps_ns + "gr_gbidy()", caps_ns + "gr_gbnumf()", caps_ns + "gr_gbnumx()", caps_ns + "gr_gbnumy()",
				caps_ns + "gr_atidminf()", caps_ns + "gr_atidminx()", caps_ns + "gr_atidminy()", caps_ns + "gr_barrier()", caps_ns + "gr_btnumy()" };
		static const int CAPS_var_count = 8;
		static const std::string CAPS_Variables_List[] = { caps_ns + "s08", caps_ns + "s16", caps_ns + "s32", caps_ns + "s64", caps_ns + "u08", caps_ns + "u16", caps_ns + "u32", caps_ns + "u64" };
	}
}
#endif /* CAPSACCRUNTIMECONST_CXX_ */

