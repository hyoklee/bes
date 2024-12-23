// -*- mode: c++; c-basic-offset:4 -*-
//
// StringStream.h
//
// This file is part of BES JSON File Out Module
//
// Copyright (c) 2014 OPeNDAP, Inc.
// Author: Nathan Potter <ndp@opendap.org>
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.
// (c) COPYRIGHT URI/MIT 1995-1999
// Please read the full copyright statement in the file COPYRIGHT_URI.
//

#ifndef STREAMSTRING_H_
#define STREAMSTRING_H_

#include <libdap/Str.h>

namespace libdap {

class StreamString: public Str{

public:

	StreamString(const string &n): Str(n) {};
	StreamString(const string &n, const string &d): Str(n,d) {}

    virtual ~StreamString()
    {}

    StreamString(const Str &copy_from): Str(copy_from){}


	friend ostream& operator<<(ostream& out, const Str& s) // output
	{
		out <<  s.value();

		return out;
	}

	friend istream& operator>>(istream& in, Str& s) // input
	{
		string tmp;
		in >> tmp;
		s.set_value(tmp);

		return in;
	}

};

} /* namespace libdap */

#endif /* STREAMSTRING_H_ */
