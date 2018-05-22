/**
Software License Agreement (proprietary)

\file      resource_resolver.h
\authors   Enrique Fernandez <efernandez@clearpathrobotics.com>
\copyright Copyright (c) 2018, Clearpath Robotics, Inc., All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
is not permitted without the express permission of Clearpath Robotics.
*/

#ifndef RESOURCE_RESOLVER_RESOURCE_RESOLVER_H
#define RESOURCE_RESOLVER_RESOURCE_RESOLVER_H

#include <cstring>
#include <string>

namespace resource_resolver
{

/**
 * @brief Resource resolver.
 * This differs from the ROS resource_retriever package (https://github.com/ros/resource_retriever) in the fact that it
 * only resolves/converts the URL string, but does not retrieve
 * any actual data.
 */
class ResourceResolver
{
public:
  /// Package resource prefix:
  static constexpr const char* PACKAGE_PREFIX = "package://";

  /// Package resource prefix length:
  static constexpr auto PACKAGE_PREFIX_LENGTH = strlen(PACKAGE_PREFIX);

  /**
   * @brief Constructor
   */
  ResourceResolver()
  {
  }

  /**
   * @brief Resolves an URL path, checking for the package prefix package://PACKAGE/rest/of/url.
   * @param[in, out] url Input URL which is resolved if it's a package resource, replacing the package path.
   */
  static void resolvePath(std::string& url)
  {
    // Check if the URL starts with the package prefix:
    if (url.find(PACKAGE_PREFIX) == 0)
    {
      // Resolve (and replace) the package resource with its actual path:
      resolvePackagePath(url);
    }
  }

private:
  /**
   * @brief Resolves an URL path with package prefix package://PACKAGE/rest/of/url.
   * @param[in, out] url Input URL which is resolved replacing the package path.
   */
  static void resolvePackagePath(std::string& url);
};

}  // namespace resource_resolver

#endif  // RESOURCE_RESOLVER_RESOURCE_RESOLVER_H
