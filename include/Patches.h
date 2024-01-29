#pragma once
#include "DKUtil/Hook.hpp"

namespace SDF
{

	struct AddStaggerActorPatch : Xbyak::CodeGenerator
	{
		static void Install()
		{
			const AddStaggerActorPatch fix{};
			const auto funcAddr = REL::RelocationID(34188, 34982).address();  //1.5.97 140563460		//1.6.1170 1405D41B0
			DKUtil::Hook::WritePatch(funcAddr + REL::Relocate(0x69, 0x69, 0x69), &fix);
			INFO("{} Done!", __FUNCTION__);
		}

	private:
		AddStaggerActorPatch()
		{
			mov(r8, rbx);
		}
	};

}