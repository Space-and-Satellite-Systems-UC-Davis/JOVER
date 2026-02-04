# MoveIt Setup — Binary Packages (No Source Build)

Original: [Your First C++ MoveIt Project](https://moveit.picknik.ai/main/doc/tutorials/your_first_project/your_first_project.html)

---

## Running the Tutorial

Open two terminals inside the devcontainer.

### Terminal 1 — Robot + MoveIt + RViz

```bash
source /opt/ros/jazzy/setup.bash
ros2 launch moveit_resources_panda_moveit_config demo.launch.py
```

This starts:
- `ros2_control_node` with mock Panda hardware (no physical robot needed)
- Controllers: `joint_state_broadcaster`, `panda_arm_controller`, `panda_hand_controller`
- `robot_state_publisher` + static TF `world -> panda_link0`
- `move_group` — the MoveIt planning/execution action server
- `rviz2` with the MotionPlanning GUI panel configured for group `panda_arm`

### RViz MotionPlanning Plugin Settings

`demo.launch.py` pre-configures these, but verify under Displays > MotionPlanning if anything looks wrong:

| Field | Value | Note |
|---|---|---|
| Robot Description | `robot_description` | Standard topic, same for any robot |
| Planning Scene Topic | `/monitored_planning_scene` | Published by `move_group` |
| Planned Path > Trajectory Topic | `/display_planned_path` | Published by `move_group` |
| Planning Group | `panda_arm` | Panda-specific. Do NOT use `manipulator` — that is the Kinova Gen 3 group name |

### Terminal 2 — Build and run your code

```bash
source /opt/ros/jazzy/setup.bash
cd /workspace
colcon build --packages-select hello_moveit
source install/setup.bash
ros2 run hello_moveit hello_moveit
```

The node connects to the running `move_group`, plans to pose (x=0.28, y=-0.2, z=0.5), and executes. The trajectory plays back in RViz.

---

## Source vs Binary: What Changes

The official tutorial builds MoveIt from source. This table covers every step that differs when using binary packages instead.

### Changed

| Step | Official tutorial (source) | This setup (binary) |
|---|---|---|
| Install MoveIt | `vcs import` + `colcon build` (~30 MoveIt repos) | `apt-get install` of 16 packages in the Dockerfile (done for you in the container) |
| Launch the demo | `ros2 launch moveit2_tutorials demo.launch.py` | `ros2 launch moveit_resources_panda_moveit_config demo.launch.py` |
| Build scope | `colcon build --mixin release` (MoveIt + your code) | `colcon build --packages-select hello_moveit` (your code only) |
| Workspace sourcing | `source ~/ws_moveit/install/setup.bash` | `source /opt/ros/jazzy/setup.bash` then `source /workspace/install/setup.bash` |

`moveit2_tutorials` only exists if you built it from source. `moveit_resources_panda_moveit_config` is the binary package that ships the same Panda demo launch file — same nodes, same controllers, same RViz config.

### Unchanged — no edits needed

| Item | Why it's the same |
|---|---|
| `#include <moveit/move_group_interface/move_group_interface.hpp>` | Headers install to `/opt/ros/jazzy/include/` regardless of source or binary |
| `CMakeLists.txt` (`find_package`, `ament_target_dependencies`) | Resolves via ament cmake configs installed to the same path either way |
| `package.xml` (`<depend>moveit_ros_planning_interface</depend>`) | This is the ament package name; the Debian package installs it transparently |
| `ros2 run hello_moveit hello_moveit` | Your package and executable names don't change |

---

## Installed Binary Packages

All installed in `.devcontainer/Dockerfile` under the `INSTALL_MOVEIT` block:

| Package | Role |
|---|---|
| `ros-jazzy-moveit` | Meta package — pulls in the core MoveIt stack |
| `ros-jazzy-moveit-resources-panda-moveit-config` | Panda URDF, SRDF, MoveIt config, and `demo.launch.py` |
| `ros-jazzy-moveit-visual-tools` | Visual debugging markers in RViz |
| `ros-jazzy-rviz-visual-tools` | Base visual tools library |
| `ros-jazzy-moveit-task-constructor-core` | Task-level motion planning |
| `ros-jazzy-moveit-py` | Python bindings for MoveIt |
| `ros-jazzy-warehouse-ros-sqlite` | SQLite-backed scene persistence |
| `ros-jazzy-ros2-control` | Hardware abstraction layer |
| `ros-jazzy-controller-manager` | Controller lifecycle management |
| `ros-jazzy-joint-trajectory-controller` | Executes joint trajectories |
| `ros-jazzy-joint-state-broadcaster` | Publishes joint states |
| `ros-jazzy-joint-state-publisher` | Joint state publisher |
| `ros-jazzy-robot-state-publisher` | Publishes TF from URDF |
| `ros-jazzy-rviz2` | 3D visualization |
| `ros-jazzy-xacro` | URDF macro preprocessor |
| `ros-jazzy-joy` | Joystick input |

Note: The `ros-jazzy-moveit` meta package does NOT transitively pull `moveit-task-constructor-core`, `moveit-py`, `moveit-resources-panda-moveit-config`, `warehouse-ros-sqlite`, the ros2-control stack, `xacro`, or `joy`. All must be listed explicitly.

---

## Planning Group Names

The Panda SRDF (from `moveit-resources-panda-moveit-config`) defines three groups:

| Group | Joints |
|---|---|
| `panda_arm` | 7 arm joints (panda_joint1 through panda_joint7) |
| `hand` | 2 finger joints |
| `panda_arm_hand` | All 9 joints |

Use `panda_arm` in your `MoveGroupInterface` for arm-only planning (this is what the tutorial and `demo.launch.py` default to).
