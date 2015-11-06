/////////////////////////////////////////////////////////////////////////////
// This file is part of the Journey MMORPG client                           //
// Copyright � 2015 Daniel Allendorf                                        //
//                                                                          //
// This program is free software: you can redistribute it and/or modify     //
// it under the terms of the GNU Affero General Public License as           //
// published by the Free Software Foundation, either version 3 of the       //
// License, or (at your option) any later version.                          //
//                                                                          //
// This program is distributed in the hope that it will be useful,          //
// but WITHOUT ANY WARRANTY; without even the implied warranty of           //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the            //
// GNU Affero General Public License for more details.                      //
//                                                                          //
// You should have received a copy of the GNU Affero General Public License //
// along with this program.  If not, see <http://www.gnu.org/licenses/>.    //
//////////////////////////////////////////////////////////////////////////////
#pragma once
#include "NxFileManager.h"
#include "nx.hpp"
#include "node.hpp"
#include "bitmap.hpp"
#include <string>
#include <fstream>
#include <stdio.h>

namespace Util
{
	using::std::string;
	// Names of game files in alphabetical order.
	const string nxfiles[NUM_FILES] =
	{
		"Character.nx", "Effect.nx", "Etc.nx", "Item.nx", "Map.nx", "Mob.nx", "Npc.nx", 
		"Quest.nx", "Reactor.nx", "Skill.nx", "Sound.nx", "String.nx", "TamingMob.nx", "UI.nx"
	};

	NxFileManager::NxFileManager() {}

	NxFileManager::~NxFileManager() {}

	bool NxFileManager::init() const
	{
		// Check if all files exists.
		for (size_t i = 0; i < NUM_FILES; i++)
		{
			if (!exists(i))
			{
				return false;
			}
		}

		// Initialise nolifenx. Load a test bitmap incase some genius forgot 
		// to set the flag for including bitmaps in their .nx files.
		nl::nx::load_all();
		nl::bitmap bmptest = nl::nx::ui["Login.img"]["Common"]["frame"].get_bitmap();
		return bmptest.data() != nullptr;
	}

	string NxFileManager::gethash(size_t index, uint64_t seed) const
	{
		return (index < NUM_FILES) ? hashutil.getfilehash(nxfiles[index].c_str(), seed) : 0;
	}

	string NxFileManager::gethash(size_t index) const
	{
		return (index < NUM_FILES) ? hashutil.getfilehash(nxfiles[index].c_str()) : 0;
	}

	bool NxFileManager::exists(size_t index) const
	{
		// Open file, store if loading successfull and close it.
		using::std::ifstream;
		ifstream f;
		f.open(nxfiles[index].c_str());
		bool success = f.good();
		f.close();
		return success;
	}
}