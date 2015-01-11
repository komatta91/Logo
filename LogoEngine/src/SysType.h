#pragma once

enum SysType {
		np, 
        wst,
		pw, 
		lw, 
		czekaj, 
		pod, 
		opu, 
		zmaz, 
		wroc, 
		czysc, 
		powtorz, 
		oto, 
		juz, 
		jesli,
		ident,      //napis
		intconst,   //sta�a
		becomes,    // '='
		define,     // ':'
		nl,         // '\n'
					// operatory arytmetyczne
		times,      // '*'
		divop,        // '/'
		plus,       // '+'
		minus,      // '-'
					// operatory logiczne
		ltop,       // '<'
		leop,            // '<='
		gtop,			// '>'
		geop,			// '>='
		eqop,			// '=='
		neop,			// '<>'
					// nawiasy
		lbracket,	// '['
		rbracket,	// ']'
		lparent,	// '('
		rparent,	    // ')'
		end,        //koniec
		error
	};
