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
#include "Journey.h"
#ifndef JOURNEY_USE_OPENGL
#include "FontsDW.h"

namespace IO
{
	void FontsDW::init(IDWriteFactory* dwf, ID2D1RenderTarget* target)
	{
		dwfactory = dwf;

		dwfactory->CreateTextFormat(L"Times New Roman", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &fonts[DWF_TEXTFIELD]);
		fonts[DWF_TEXTFIELD]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		fonts[DWF_TEXTFIELD]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 12.0f, L"en-us", &fonts[DWF_12ML]);
		fonts[DWF_12ML]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		fonts[DWF_12ML]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_LIGHT, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 12.0f, L"en-us", &fonts[DWF_12LL]);
		fonts[DWF_12LL]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		fonts[DWF_12LL]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 12.0f, L"en-us", &fonts[DWF_12MC]);
		fonts[DWF_12MC]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		fonts[DWF_12MC]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 12.0f, L"en-us", &fonts[DWF_12BC]);
		fonts[DWF_12BC]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		fonts[DWF_12BC]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 12.0f, L"en-us", &fonts[DWF_12MR]);
		fonts[DWF_12MR]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		fonts[DWF_12MR]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &fonts[DWF_14ML]);
		fonts[DWF_14ML]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_LEADING);
		fonts[DWF_14ML]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &fonts[DWF_14MC]);
		fonts[DWF_14MC]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		fonts[DWF_14MC]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &fonts[DWF_14BC]);
		fonts[DWF_14BC]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		fonts[DWF_14BC]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 14.0f, L"en-us", &fonts[DWF_14MR]);
		fonts[DWF_14MR]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_TRAILING);
		fonts[DWF_14MR]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		dwfactory->CreateTextFormat(L"Calibri", NULL, DWRITE_FONT_WEIGHT_NORMAL, DWRITE_FONT_STYLE_NORMAL, DWRITE_FONT_STRETCH_NORMAL, 20.0f, L"en-us", &fonts[DWF_20MC]);
		fonts[DWF_20MC]->SetTextAlignment(DWRITE_TEXT_ALIGNMENT_CENTER);
		fonts[DWF_20MC]->SetParagraphAlignment(DWRITE_PARAGRAPH_ALIGNMENT_NEAR);

		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &brushes[TXC_WHITE]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Black), &brushes[TXC_BLACK]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Yellow), &brushes[TXC_YELLOW]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Blue), &brushes[TXC_BLUE]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Red), &brushes[TXC_RED]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Brown), &brushes[TXC_BROWN]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Gray), &brushes[TXC_GREY]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Orange), &brushes[TXC_ORANGE]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::SkyBlue), &brushes[TXC_MBLUE]);
		target->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::Violet), &brushes[TXC_VIOLET]);
	}

	FontsDW::~FontsDW()
	{
		for (map<Font, IDWriteTextFormat*>::iterator fnit = fonts.begin(); fnit != fonts.end(); ++fnit)
		{
			fnit->second->Release();
		}
		for (map<Textcolor, ID2D1SolidColorBrush*>::iterator brit = brushes.begin(); brit != brushes.end(); ++brit)
		{
			brit->second->Release();
		}
	}

	IDWriteTextFormat* FontsDW::getfont(Font f) const
	{
		return fonts.count(f) ? fonts.at(f) : nullptr;
	}

	ID2D1SolidColorBrush* FontsDW::getbrush(Textcolor col) const
	{
		return brushes.count(col) ? brushes.at(col) : nullptr;
	}

	IDWriteFactory* FontsDW::getdwfactory() const
	{
		return dwfactory;
	}
}
#endif