# Build projects
### With QtCreator.
- At the root of the `qt-projects` folder, create a build directory.
- In QtCreator, click on the Projects button on the left, then set the Build Directory.

### With qmake:
From within the `bmi` or `temperature` folders, run:

```bash
mkdir build && cd build
qmake ..
make
```


# Qt notions
### Update (end of 2023)
- `Qt` examples use raw pointers partly for historical reasons; for compatibility with older versions, to support multiple platforms, and finally because Qt was released when there was no smart pointers.
- Even with raw pointers, memory is managed hierarchically, i.e. deleting an object automatically destroys all its children.
- In the cpp code, the UI communicates with the main cpp class based on the structure explained [here][ui].

[ui]: https://doc.qt.io/qt-6/designer-using-a-ui-file.html#the-single-inheritance-approach

### QtWidgets lifetime
- `QtWidget` are initialized with pointers (i.e. in the heap) since they need to exist for as long as the application is running.
- Pointers to QWidget objectes are created in the heap with the keyword `new`. If they were created in the function's stack, they will be destroyed when its scope ends, which isn't practical since Qt's `slots` need to have access to these widgets.
- There's typically only one heap per application, while each thread gets a stack (stack allocation is faster).
- Why not a reference?: A reference in the C++ standard is just an alias to a variable (not a variable that holds a memory address), so no dynamic memory allocation like with pointers. For pointers, the user is responsible of freeing the memory once done with it.

### QObject
- When a `QObject` is deleted, its children are automatically deleted too.

### OOP
- By default access to members of a C++ class is private.

### Signals and signals
- Signals and slots are both functions with or without arguments.
- A Signal has at least as many arguments as the Slot associated to it, and with the same type.
- These arguments represent the data sent from the signal to the slot.
- Besides the SLOT and SIGNAL macros, `connect()` can also receive the signal and slot as pointers to member functions.
