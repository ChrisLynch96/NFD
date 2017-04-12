/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/**
 * Copyright (c) 2014-2017,  Regents of the University of California,
 *                           Arizona Board of Regents,
 *                           Colorado State University,
 *                           University Pierre & Marie Curie, Sorbonne University,
 *                           Washington University in St. Louis,
 *                           Beijing Institute of Technology,
 *                           The University of Memphis.
 *
 * This file is part of NFD (Named Data Networking Forwarding Daemon).
 * See AUTHORS.md for complete list of NFD authors and contributors.
 *
 * NFD is free software: you can redistribute it and/or modify it under the terms
 * of the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * NFD is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * NFD, e.g., in COPYING.md file.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef NFD_TOOLS_NFDC_COMMAND_ARGUMENTS_HPP
#define NFD_TOOLS_NFDC_COMMAND_ARGUMENTS_HPP

#include "core/common.hpp"
#include "status-report.hpp"
#include <ndn-cxx/encoding/nfd-constants.hpp>
#include <ndn-cxx/util/face-uri.hpp>
#include <boost/any.hpp>

namespace nfd {
namespace tools {
namespace nfdc {

using ndn::nfd::FacePersistency;
using ndn::nfd::RouteOrigin;
using ndn::util::FaceUri;

/** \brief contains named command arguments
 */
class CommandArguments : public std::map<std::string, boost::any>
{
public:
  /** \return the argument value, or a default value if the argument is omitted on command line
   */
  template<typename T>
  T
  get(const std::string& key, const T& defaultValue = T()) const
  {
    auto i = find(key);
    return i == end() ? defaultValue : boost::any_cast<T>(i->second);
  }

  /** \return the argument value, or nullopt if the argument is omitted on command line
   */
  template<typename T>
  ndn::optional<T>
  getOptional(const std::string& key) const
  {
    auto i = find(key);
    if (i == end()) {
      return ndn::nullopt;
    }
    return boost::any_cast<T>(i->second);
  }
};

} // namespace nfdc
} // namespace tools
} // namespace nfd

#endif // NFD_TOOLS_NFDC_COMMAND_ARGUMENTS_HPP
