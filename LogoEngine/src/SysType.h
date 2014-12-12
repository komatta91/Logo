#pragma once

enum SysType {
		np, 
		ws, 
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
		intconst,   //sta³a
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
		error
	};