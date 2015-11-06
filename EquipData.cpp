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
#include "EquipData.h"
#include "nx.hpp"

namespace Data
{
	const size_t NUM_TRANSPARENT = 1;

	const int32_t transparentequips[NUM_TRANSPARENT] =
	{
		1002186
	};

	EquipData::EquipData(int32_t equipid, const BodyDrawinfo& drawinfo) : ItemData(equipid)
	{
		CharacterLayer chlayer;
		int32_t prefix = equipid / 10000;
		switch (prefix)
		{
		case 100:
			chlayer = CL_HAT;
			eqslot = Character::EQL_CAP;
			type = "HAT";
			break;
		case 101:
			chlayer = CL_FACEACC;
			eqslot = Character::EQL_FACEACC;
			type = "FACE ACCESSORY";
			break;
		case 102:
			chlayer = CL_EYEACC;
			eqslot = Character::EQL_EYEACC;
			type = "EYE ACCESSORY";
			break;
		case 103:
			chlayer = CL_EARRINGS;
			eqslot = Character::EQL_EARRINGS;
			type = "EARRINGS";
			break;
		case 104:
			chlayer = CL_TOP;
			eqslot = Character::EQL_TOP;
			type = "TOP";
			break;
		case 105:
			chlayer = CL_MAIL;
			eqslot = Character::EQL_TOP;
			type = "OVERALL";
			break;
		case 106:
			chlayer = CL_PANTS;
			eqslot = Character::EQL_PANTS;
			type = "BOTTOM";
			break;
		case 107:
			chlayer = CL_SHOES;
			eqslot = Character::EQL_SHOES;
			type = "SHOES";
			break;
		case 108:
			chlayer = CL_GLOVE;
			eqslot = Character::EQL_GLOVES;
			type = "GLOVES";
			break;
		case 109:
			chlayer = CL_SHIELD;
			eqslot = Character::EQL_SHIELD;
			type = "SHIELD";
			break;
		case 110:
			chlayer = CL_CAPE;
			eqslot = Character::EQL_CAPE;
			type = "CAPE";
			break;
		case 111:
			chlayer = CL_RING;
			eqslot = Character::EQL_RING;
			type = "RING";
			break;
		case 112:
			chlayer = CL_PENDANT;
			eqslot = Character::EQL_PENDANT;
			type = "PENDANT";
			break;
		case 113:
			chlayer = CL_BELT;
			eqslot = Character::EQL_BELT;
			type = "BELT";
			break;
		case 114:
			chlayer = CL_MEDAL;
			eqslot = Character::EQL_MEDAL;
			type = "MEDAL";
			break;
		default:
			if (prefix >= 130 && prefix <= 170)
			{
				chlayer = CL_WEAPON;
				eqslot = Character::EQL_WEAPON;

				switch (prefix)
				{
				case 130:
					type = "ONE-HANDED SWORD";
					break;
				case 131:
					type = "ONE-HANDED AXE";
					break;
				case 132:
					type = "ONE-HANDED MACE";
					break;
				case 133:
					type = "DAGGER";
					break;
				case 137:
					type = "WAND";
					break;
				case 138:
					type = "STAFF";
					break;
				case 140:
					type = "TWO-HANDED SWORD";
					break;
				case 141:
					type = "TWO-HANDED AXE";
					break;
				case 142:
					type = "TWO-HANDED MACE";
					break;
				case 143:
					type = "SPEAR";
					break;
				case 144:
					type = "POLEARM";
					break;
				case 145:
					type = "BOW";
					break;
				case 146:
					type = "CROSSBOW";
					break;
				case 147:
					type = "CLAW";
					break;
				case 148:
					type = "KNUCKLE";
					break;
				case 149:
					type = "GUN";
					break;
				}
			}
		}

		using::nl::node;
		node equipnode = nl::nx::character[getcategory()]["0" + std::to_string(equipid) + ".img"];
		for (node stancenode = equipnode.begin(); stancenode != equipnode.end(); ++stancenode)
		{
			string stance = stancenode.name();
			if (stance == "info")
			{
				cash = stancenode["cash"].get_bool();
				tradeblock = stancenode["tradeBlock"].get_bool();
				price = stancenode["price"];
				slots = stancenode["tuc"];

				reqstats[Character::MS_LEVEL] = stancenode["reqLevel"];
				reqstats[Character::MS_JOB] = stancenode["reqJob"];
				reqstats[Character::MS_STR] = stancenode["reqSTR"];
				reqstats[Character::MS_DEX] = stancenode["reqDEX"];
				reqstats[Character::MS_INT] = stancenode["reqINT"];
				reqstats[Character::MS_LUK] = stancenode["reqLUK"];

				defstats[Character::ES_STR] = stancenode["incSTR"];
				defstats[Character::ES_DEX] = stancenode["incDEX"];
				defstats[Character::ES_INT] = stancenode["incINT"];
				defstats[Character::ES_LUK] = stancenode["incLUK"];
				defstats[Character::ES_WATK] = stancenode["incPAD"];
				defstats[Character::ES_WDEF] = stancenode["incPDD"];
				defstats[Character::ES_MAGIC] = stancenode["incMAD"];
				defstats[Character::ES_MDEF] = stancenode["incMDD"];
				defstats[Character::ES_HP] = stancenode["incMHP"];
				defstats[Character::ES_MP] = stancenode["incMMP"];
				defstats[Character::ES_ACC] = stancenode["incACC"];
				defstats[Character::ES_AVOID] = stancenode["incEVA"];
				defstats[Character::ES_HANDS] = stancenode["incHANDS"];
				defstats[Character::ES_SPEED] = stancenode["incSPEED"];
				defstats[Character::ES_JUMP] = stancenode["incJUMP"];
			}
			else if (stance != "default" && stance != "backDefault")
			{
				uint8_t frame = 0;
				node framenode = stancenode[std::to_string(frame)];
				while (framenode.size() > 0)
				{
					for (node partnode = framenode.begin(); partnode != framenode.end(); ++partnode)
					{
						string part = partnode.name();
						if (partnode.data_type() == node::type::bitmap)
						{
							CharacterLayer z = chlayer;
							string zs = partnode["z"];
							if (z == CL_WEAPON)
							{
								if (zs == "weaponOverHand")
									z = CL_WEAPONOHAND;
								else if (zs == "weaponOverGlove")
									z = CL_WEAPONOGLOVE;
								else if (zs == "backWeaponOverShield")
									z = CL_BACKWEAPON;
							}
							else if (z == CL_SHIELD)
							{
								if (zs == "shieldOverHair")
									z = CL_SHIELDOHAIR;
								else if (zs == "shieldBelowBody")
									z = CL_SHIELDBBODY;
								else if (zs == "backShield")
									z = CL_BACKSHIELD;
							}
							else if (part == "mailArm")
							{
								z = CL_MAILARM;
							}

							stances[stance][z].add(frame, new Texture(partnode));

							string parent;
							vector2d<int> parentpos;
							node map = partnode["map"];
							for (node mapnode = map.begin(); mapnode != map.end(); mapnode++)
							{
								if (mapnode.data_type() == node::type::vector)
								{
									parent = mapnode.name();
									parentpos = vector2d<int>(mapnode.x(), mapnode.y());
								}
							}

							vector2d<int> shift = vector2d<int>();
							switch (z)
							{
							case CL_FACEACC:
								shift -= parentpos;
								break;
							case CL_TOP:
							case CL_PANTS:
							case CL_CAPE:
							case CL_SHOES:
							case CL_MAIL:
							case CL_MAILARM:
							case CL_GLOVE:
							case CL_BACKWEAPON:
							case CL_BACKSHIELD:
								shift = drawinfo.getbodypos(stance, frame) - parentpos;
								break;
							case CL_HAT:
							case CL_EARRINGS:
							case CL_EYEACC:
								shift = drawinfo.getfacepos(stance, frame) - parentpos;
								break;
							case CL_SHIELD:
							case CL_SHIELDOHAIR:
							case CL_WEAPON:
							case CL_WEAPONOHAND:
							case CL_WEAPONOGLOVE:
								if (parent == "hand")
								{
									shift += drawinfo.getarmpos(stance, frame);
								}
								else if (parent == "handMove")
								{
									shift += drawinfo.gethandpos(stance, frame);
								}
								shift += drawinfo.getbodypos(stance, frame) - parentpos;
								break;
							}

							stances[stance][z].get(frame)->setshift(shift);
						}
					}

					frame++;
					framenode = stancenode[std::to_string(frame)];
				}
			}
		}

		transparent = false;
		for (size_t i = 0; i < NUM_TRANSPARENT; i++)
		{
			if (equipid == transparentequips[i])
				transparent = true;
		}
	}

	EquipData::EquipData()
	{
		transparent = true;
		type = "";
		eqslot = Character::EQL_NONE;
	}

	bool EquipData::istransparent() const
	{
		return transparent;
	}

	const string& EquipData::gettype() const
	{
		return type;
	}

	Equipslot EquipData::geteqslot() const
	{
		return eqslot;
	}
}
