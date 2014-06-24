#ifndef _SpectrumEditor_h_
#define _SpectrumEditor_h_
/* SpectrumEditor.h
 *
 * Copyright (C) 1992-2011,2012,2013 Paul Boersma
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "FunctionEditor.h"
#include "Spectrum.h"

Thing_define (SpectrumEditor, FunctionEditor) {
	// new data:
	public:
		double minimum, maximum, cursorHeight;
		GuiMenuItem publishBandButton, publishSoundButton;
	// overridden methods:
		virtual void v_createMenus ();
		virtual void v_createHelpMenuItems (EditorMenu menu);
		virtual void v_dataChanged ();
		virtual void v_draw ();
		virtual int v_click (double xWC, double yWC, bool shiftKeyPressed);
		virtual void v_play (double tmin, double tmax);
		virtual void v_createMenuItems_view (EditorMenu menu);
		virtual const wchar_t * v_format_domain () { return L"Frequency domain:"; }
		virtual const wchar_t * v_format_short () { return L"%.0f"; }
		virtual const wchar_t * v_format_long () { return L"%.2f"; }
		virtual int v_fixedPrecision_long () { return 2; }
		virtual const wchar_t * v_format_units () { return L"hertz"; }
		virtual const wchar_t * v_format_totalDuration () { return L"Total bandwidth %.2f hertz"; }
		virtual const wchar_t * v_format_window () { return L"Visible part %.2f hertz"; }
		virtual const wchar_t * v_format_selection () { return L"%.2f Hz"; }
	#include "SpectrumEditor_prefs.h"
};

SpectrumEditor SpectrumEditor_create (const wchar_t *title, Spectrum data);

/* End of file SpectrumEditor.h */
#endif
