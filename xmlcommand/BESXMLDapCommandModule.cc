// BESXMLDapCommandModule.cc

// This file is part of bes, A C++ back-end server implementation framework
// for the DAP Data Access Protocol.

// Copyright (c) 2004-2009 University Corporation for Atmospheric Research
// Author: Patrick West <pwest@ucar.edu> and Jose Garcia <jgarcia@ucar.edu>
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
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
// You can contact University Corporation for Atmospheric Research at
// 3080 Center Green Drive, Boulder, CO 80301
 
// (c) COPYRIGHT University Corporation for Atmospheric Research 2004-2005
// Please read the full copyright statement in the file COPYRIGHT_UCAR.
//
// Authors:
//      pwest       Patrick West <pwest@ucar.edu>
//      jgarcia     Jose Garcia <jgarcia@ucar.edu>

#include <iostream>

using std::endl ;
using std::cout ;

#include "BESXMLDapCommandModule.h"
#include "BESDapNames.h"
#include "BESDebug.h"
#include "BESXMLCatalogCommand.h"
#include "BESXMLGetDataDDXCommand.h"

void
BESXMLDapCommandModule::initialize( const string &modname )
{
    BESDEBUG( "dap", "Initializing DAP Commands:" << endl ) ;

    BESDEBUG( "besxml", "    adding " << CATALOG_RESPONSE_STR
			<< " command" << endl ) ;
    BESXMLCommand::add_command( CATALOG_RESPONSE_STR,
				BESXMLCatalogCommand::CommandBuilder ) ;

    BESDEBUG( "besxml", "    adding " << SHOW_INFO_RESPONSE_STR
			<< " command" << endl ) ;
    BESXMLCommand::add_command( SHOW_INFO_RESPONSE_STR,
				BESXMLCatalogCommand::CommandBuilder ) ;

    BESDEBUG( "besxml", "    adding " << DATADDX_RESPONSE
			<< " command" << endl ) ;
    BESXMLCommand::add_command( DATADDX_RESPONSE,
				BESXMLGetDataDDXCommand::CommandBuilder ) ;

    BESDEBUG( "dap", "Done Initializing DAP Commands:" << endl ) ;
}

void
BESXMLDapCommandModule::terminate( const string &modname )
{
    BESDEBUG( "dap", "Removing DAP Commands" << endl ) ;

    BESXMLCommand::del_command( CATALOG_RESPONSE_STR ) ;
    BESXMLCommand::del_command( SHOW_INFO_RESPONSE_STR ) ;
    BESXMLCommand::del_command( DATADDX_RESPONSE ) ;

    BESDEBUG( "dap", "Done Removing DAP Commands" << endl ) ;
}

/** @brief dumps information about this object
 *
 * Displays the pointer value of this class
 *
 * @param strm C++ i/o stream to dump the information to
 */
void
BESXMLDapCommandModule::dump( ostream &strm ) const
{
    strm << BESIndent::LMarg << "BESXMLDapCommandModule::dump - ("
			     << (void *)this << ")" << endl ;
}

extern "C"
{
    BESAbstractModule *maker()
    {
	return new BESXMLDapCommandModule ;
    }
}
