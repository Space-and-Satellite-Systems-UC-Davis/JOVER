## Devcontainer
Run the setup_devcontainer.sh to get the latest version of the devcontainer.

To run the devcontainer, installed the [Dev Containers](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers) Extension.

For how to open to container, follow the [VSCode documentation](https://code.visualstudio.com/docs/devcontainers/containers#_quick-start-open-an-existing-folder-in-a-container).

You can edit the produced devcontainer file locally. To make modification remotely, see the ros-container repo.

## How to build and run the code
Presuming that you have opened the container already, you can build the code by running `colcon build` and then running `source install/setup.bash` or replace bash with your shell. Then use the `ros2 run <pkg_name> <executable_name>` or `ros2 launch <pkg_name> <launch_file_name>` command to run your packages.