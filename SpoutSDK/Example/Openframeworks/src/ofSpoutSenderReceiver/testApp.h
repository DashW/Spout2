/*

	Spout - Sender / Receiver example

	Copyright (C) 2014 Lynn Jarvis.

	This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/
#pragma once

#include "ofMain.h"	// The usual
#include "..\..\..\SpoutSDK\Spout.h"	// Spout SDK

class testApp : public ofBaseApp {

	public:

		void setup();
		void update();
		void draw();
		void mousePressed(int x, int y, int button);
		void windowResized(int w, int h);
		void exit(); 

		bool InitGLtexture(GLuint &texID, unsigned int width, unsigned int height);
		bool OpenReceiver(Spout* receiver, char* senderName, unsigned int &width, unsigned int &height);
		bool GetTexture(Spout* receiver, char* senderName, ofImage &image, unsigned int &width, unsigned int &height);

		
		bool bMemoryShare;								// Texture share compatibility

		SpoutSender *spoutsender;						// A sender object
		bool bSenderInitialized;						// Sender initialization result
		char senderName[256];							// Sender name
		GLuint senderTexture;							// OpenGL texture used by the sender
		ofImage senderImage;							// Texture image for the sender demo graphics
		unsigned int g_Width, g_Height;					// Global width and height - used by the sender

		SpoutReceiver *spoutreceiver;					// A receiver object
		bool bReceverInitialized;						// Receiver initialization result
		bool bReceived;									// Has the receiver received anything
		char receiverName[256];							// Sender name that the receiver to connects to 
		ofImage receiverImage;							// Texture image used by the receiver
		unsigned int receiverWidth, receiverHeight;		// Width and height of the receiver

};
