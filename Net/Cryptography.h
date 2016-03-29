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
#include "NetConstants.h"
#include "Journey.h"
#include <cstdint>

namespace Net
{
	// Used to encrypt and decrypt packets for communication with the server.
	class Cryptography
	{
	public:
		// Obtain the initialization vector from the handshake.
		Cryptography(const int8_t* handshake);
		Cryptography();
		~Cryptography();

		// Encrypt a byte array with the given length and iv.
		void encrypt(int8_t* bytes, size_t length);
		// Decrypt a byte array with the given length and iv.
		void decrypt(int8_t* bytes, size_t length);
		// Generate a header for the specified length and key.
		void getheader(int8_t* buffer, size_t length) const;
		// Use the 4-byte header of a received packet to determine its length.
		size_t getlength(const int8_t* header) const;

	private:
		// Add the maple custom encryption.
		void mapleencrypt(int8_t* bytes, size_t length) const;
		// Remove the maple custom encryption.
		void mapledecrypt(int8_t* bytes, size_t length) const;
		// Update a key.
		void updateiv(uint8_t* iv) const;
		// Perform a roll-left operation.
		int8_t rollleft(int8_t byte, size_t count) const;
		// Perform a roll-right operation.
		int8_t rollright(int8_t byte, size_t count) const;

		// Apply aesofb to a byte array.
		void aesofb(int8_t* bytes, size_t length, uint8_t* iv) const;
		// Encrypt a byte array with AES.
		void aesencrypt(uint8_t* bytes) const;
		// AES addroundkey step.
		void addroundkey(uint8_t* bytes, uint8_t round) const;
		// AES subbytes step.
		void subbytes(uint8_t* bytes) const;
		// AES shiftrows step.
		void shiftrows(uint8_t* bytes) const;
		// Aes mixcolumns step.
		void mixcolumns(uint8_t* bytes) const;
		// Perform a gauloise multiplication.
		uint8_t gmul(uint8_t byte) const;

#ifdef JOURNEY_USE_CRYPTO
		uint8_t sendiv[HEADER_LENGTH];
		uint8_t recviv[HEADER_LENGTH];
#endif
	};
}

