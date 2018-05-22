/**
Software License Agreement (proprietary)

\file      resource_resolver.h
\authors   Enrique Fernandez <efernandez@clearpathrobotics.com>
\copyright Copyright (c) 2018, Clearpath Robotics, Inc., All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
is not permitted without the express permission of Clearpath Robotics.
*/

#include <resource_resolver/resource_resolver.h>

#include <ros/package.h>

namespace resource_resolver
{

void ResourceResolver::resolvePackagePath(std::string& url)
{
  // Parse package name:
  const auto rest = url.find('/', PACKAGE_PREFIX_LENGTH);
  if (rest == std::string::npos)
  {
    throw std::runtime_error("Could not parse package in URL " + url + ".");
  }

  const auto package = url.substr(PACKAGE_PREFIX_LENGTH, rest - PACKAGE_PREFIX_LENGTH);

  // Resolve package path:
  const std::string package_path = ros::package::getPath(package);
  if (package_path.empty())
  {
    throw std::runtime_error("Could not find package " + package + ".");
  }

  url.replace(0, rest, package_path);
}

}  // namespace resource_resolver
