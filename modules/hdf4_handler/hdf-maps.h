// This file is part of the hdf4 data handler for the OPeNDAP data server.

// Copyright (c) 2005 OPeNDAP, Inc.
// Author: James Gallagher <jgallagher@opendap.org>
//
// This is free software; you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free
// Software Foundation; either version 2.1 of the License, or (at your
// option) any later version.
// 
// This software is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public
// License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this software; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
//
// You can contact OPeNDAP, Inc. at PO Box 112, Saunderstown, RI. 02874-0112.

/////////////////////////////////////////////////////////////////////////////
// Copyright 1998, by the California Institute of Technology.
// ALL RIGHTS RESERVED. United States Government Sponsorship
// acknowledged. Any commercial use must be negotiated with the
// Office of Technology Transfer at the California Institute of
// Technology. This software may be subject to U.S. export control
// laws and regulations. By accepting this software, the user
// agrees to comply with all applicable U.S. export laws and
// regulations. User has the responsibility to obtain export
// licenses, or other export authority as may be required before
// exporting such information to foreign countries or providing
// access to foreign persons.

// Author: Jake Hamby, NASA/Jet Propulsion Laboratory
//         Jake.Hamby@jpl.nasa.gov
//

// STL map include
#include <map>

using std::map;
using std::less;

struct sds_info {
    hdf_sds sds;
    bool in_vgroup;
};

struct vd_info {
    hdf_vdata vdata;
    bool in_vgroup;
};

struct gr_info {
    hdf_gri gri;
    bool in_vgroup;
};

struct vg_info {
    hdf_vgroup vgroup;
    bool toplevel;
};

using sds_map =  map < int32, sds_info, less < int32 > >;
using vd_map = map < int32, vd_info, less < int32 > >;
using gr_map = map < int32, gr_info, less < int32 > > ;
using vg_map =  map < int32, vg_info, less < int32 > >;

using SDSI =  map < int32, sds_info, less < int32 > >::const_iterator;
using VDI =  map < int32, vd_info, less < int32 > >::const_iterator;
using GRI = map < int32, gr_info, less < int32 > >::const_iterator;
using VGI = map < int32, vg_info, less < int32 > >::const_iterator;

/* Function prototypes */
HDFGrid *NewGridFromSDS(const hdf_sds & sds, const string &dataset);
HDFArray *NewArrayFromSDS(const hdf_sds & sds, const string &dataset);
HDFArray *NewArrayFromGR(const hdf_gri & gr, const string &dataset);
HDFSequence *NewSequenceFromVdata(const hdf_vdata & vd, const string &dataset);
HDFStructure *NewStructureFromVgroup(const hdf_vgroup & vg,
                                     vg_map & vgmap, sds_map & map,
                                     vd_map & vdmap, gr_map & grmap,
				     const string &dataset);
libdap::BaseType *NewDAPVar(const string &varname,
		    const string &dataset,
		    const int32 hdf_type);
string DAPTypeName(int32 hdf_type);
