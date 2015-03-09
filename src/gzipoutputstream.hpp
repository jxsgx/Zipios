#pragma once
/*
  Zipios++ - a small C++ library that provides easy access to .zip files.
  Copyright (C) 2000-2015  Thomas Sondergaard

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307  USA
*/

/** \file
 * \brief Header file that defines GZIPOutputStream.
 */

#include "gzipoutputstreambuf.hpp"

#include <memory>


namespace zipios
{


class GZIPOutputStream : public std::ostream
{
public:
    explicit  GZIPOutputStream(std::ostream& os);
    explicit  GZIPOutputStream(std::string const& filename);
    virtual   ~GZIPOutputStream();

    void      setFilename(std::string const& filename);
    void      setComment(std::string const& comment);
    void      close();
    void      finish();

private:
    std::unique_ptr<std::ofstream>        m_ofs;
    std::unique_ptr<GZIPOutputStreambuf>  m_ozf;
};


} // zipios namespace.
// vim: ts=4 sw=4 et