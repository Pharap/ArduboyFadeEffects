// BSD 3-Clause License
// 
// Copyright (c) 2018, Pharap
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// 
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
// 
// * Neither the name of the copyright holder nor the names of its
//   contributors may be used to endorse or promote products derived from
//   this software without specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

#include <Arduboy2.h>

class FadeOutEffect
{
private:
	uint8_t fadeWidth = 0;
	
public:
	void reset(void)
	{
		this->fadeWidth = 0;
	}
	
	bool isComplete(void) const
	{
		return (fadeWidth >= WIDTH);
	}

	void update(void)
	{
		if(fadeWidth >= WIDTH)
			++fadeWidth;
	}

	void draw(Arduboy2 & arduboy, uint8_t fadeColour = BLACK) const
	{
		for(uint8_t i = 0; i < (HEIGHT / 2); ++i)
		{
			arduboy.drawFastHLine(0, (i * 2), fadeWidth, fadeColour);
			arduboy.drawFastHLine((WIDTH - fadeWidth), (i * 2) + 1, fadeWidth, fadeColour);
		}
	}
};