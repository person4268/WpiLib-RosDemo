# RosDemo

This is a demonstration of rclcpp compiled for the RoboRIO and for simulation, and is integrated with the WpiLib toolchain, through the use of vendordeps.

The vendordeps are currently only shared libraries for linuxx86-64 and linuxathena (the RoboRIO), but it should be possible to add the precompiled Windows ROS shared libraries with a little work.

The x86 shared libraries were created from compiling ROS on Arch Linux, and might not work on other distributions. The shared libraries were more or less copied by taking the names of the athena ones, and copying all files in /opt/ros2/galactic with the same name, and then copying them into another folder, fixing dependencies with ldd and common sense(+guesswork
) and then zipping them up into a vendordep zip. **If you are setting up another architecture, you cannot copy every file. NativeUtils tries to link against every library in the vendordep, and some are unrelated to rclcpp and some are likely mutually exclusive. It will crash at runtime.**

The distribution of ROS used was ROS Galactic, which will be EOL soon, since that's what https://github.com/person4268/RoborioROS2 (which is a fork of another team's project) uses, but it could be updated in theory by updating the submodules among some other stuff.

GradleRIO scans the project root for maven packages, so we can get away with putting the zips in the project root. 

It's somewhat of a miracle that this even works.
