# btnmyscript

WiringPi based program that let you control (run & kill) others script using GPIO Buttons.

-------------------------------------------------------------------------------------------------------------------------

**Notes:**
  * To build and use this program, you need to have installed WiringPi library in your system.
  * In order to access the GPIO, to use the program you need to call It with admin privileges (sudo).

**Installation and use:**
  1. Get the sources:
  ```shell
  git clone https://github.com/J-Rios/btnmyscript
  cd btnmyscript
  ```

  2. Build the main program:
  ```shell
  gcc -o btnmyscript btnmyscript.c -lwiringPi
  ```

  3. Copy to the global PATH /usr/bin, the program sources:
  ```shell
  sudo cp -a btnmyscript /usr/bin/
  sudo cp -a run_mysh.sh /usr/bin/
  sudo cp -a stop_mysh.sh /usr/bin/
  ```
  
  4. (Optional) Delete the downloaded, and now unnecessary, repository:
  ```shell
  cd ..
  sudo rm -rf btnmyscript
  ```
  
  5. Example of use the program:
  ```shell
  sudo btnmyscript path/script/to/control &
  ```
  
