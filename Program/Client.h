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
#include "Net\SessionServer.h"
#include "Audio\AudioplayerBass.h"
#include "Util\NxFileManager.h"
#include "IO\UI.h"
#include "Gameplay\Stage.h"
#include "ClientInterface.h"

#include "Journey.h"
#ifdef JOURNEY_USE_OPENGL
#include "IO\WindowGLFW.h"
#else
#include "IO\WindowD2D.h"
#endif

namespace Journey
{
#ifdef JOURNEY_USE_OPENGL
	using::IO::WindowGLFW;
#else
	using::IO::WindowD2D;
#endif

	using::Net::SessionServer;
	using::Audio::AudioplayerBass;
	using::Util::Configuration;
	using::Gameplay::Stage;

	// Topmost class in the hierarchy that represents the program itself. Contains all game- and networking-objects.
	class Client : public ClientInterface
	{
	public:
		// Error codes to be checked after initialisation.
		enum Error
		{
			NONE,
			NXFILES,
			CONNECTION,
			WINDOW,
			AUDIO
		};

		Client();
		~Client();
		// Returns the last error code.
		Error geterror() const;
		// Checks for incoming packets and returns if the connection is still alive.
		bool receive();
		// Draws the window and all game objects.
		void draw(float) const;
		// Processes inputs and updates the window and all game objects.
		// Parameters: short(delay-per-frame)
		void update(uint16_t);
		// Methods for obtaining references to game objects.
		Audioplayer& getaudio();
		StageInterface& getstage();
		UI& getui();
		Session& getsession();
		Configuration& getconfig();
		NxFileManager& getnxfiles();
	private:

#ifdef JOURNEY_USE_OPENGL
		WindowGLFW window;
#else
		WindowD2D window;
#endif

		AudioplayerBass audioplayer;
		NxFileManager nxfiles;
		Stage stage;
		UI ui;
		SessionServer session;
		Configuration config;
		Error error;
	};
}
