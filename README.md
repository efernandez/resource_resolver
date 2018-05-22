# resource_resolver
Resource resolver for ROS packages

This allows to use `package://package_name/config/example_config.yaml` in YAML files and resolves `package:://package_name` into the full path to the `package_name` package.

This code is similar to the resource retriever in some Rviz plugins, but provides a clean API to do the same in any ROS package.

However, after ROS Melodic (in particular this PR: https://github.com/ros/ros_comm/pull/1354) we can't also do `$(find package_name)/config/example_config.yaml` if we load the YAML file from a launch file using the `subst_value="true"` argument when loading with `rosparam`.
