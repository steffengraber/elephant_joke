# Elephant Joke

A minimal example project for a C++ extension with Python bindings (pybind11), built with **scikit-build-core**.

## Description

This project demonstrates how to:
- Export a simple C++ function to Python using pybind11
- Use scikit-build-core as a build system for hybrid C++/Python projects
- Implement dynamic versioning from a VERSION file
- Build wheels for multiple platforms using cibuildwheel
- Automatically deploy to PyPI via GitHub Actions

---

## Requirements

- Python >= 3.8
- pip >= 23.0
- C++17 compatible compiler (GCC, Clang, MSVC)
- CMake >= 3.18

---

## Installation

### From Source
```bash
git clone https://github.com/USER/elephant_joke.git
cd elephant_joke
pip install .
```

### From PyPI
```bash
pip install elephant-joke
```

---

## Usage

```python
from elephant_joke import elephant_joke, __version__

print(f"v{__version__}: {elephant_joke()}")
```
**Output:**
```
v3.13.0rc1: Warum tragen Elefanten keine Turnschuhe? - Weil sie sonst die ganze Savanne auslaufen!
```

---

## Project Structure

```
elephant_joke/
├── CMakeLists.txt          # CMake configuration for pybind11
├── VERSION                 # Version file (dynamically read)
├── pyproject.toml          # Build system configuration
├── src/
│   └── elephant_joke.cpp   # C++ source code with pybind11 bindings
├── elephant_joke/
│   └── __init__.py         # Python package interface
├── .github/
│   └── workflows/
│       └── wheels.yml      # CI/CD pipeline (cibuildwheel + PyPI)
└── LICENSE                 # MIT License
```

---

## Development

### Editable Install
```bash
pip install -e .
```

### Versioning
The version is dynamically read from the `VERSION` file and transformed:
- `3.13.0_rc1` -> `3.13.0rc1`
- `3.10_dev1` -> `3.10.dev1`

### Build Wheel (Local)
```bash
pip wheel . --no-deps
```
-> Generates `elephant_joke-<version>-<platform>.whl` in the `dist/` directory.

---

## Deployment

### Automatic (GitHub Actions)
- **Trigger:** Tag push (`git tag v3.13.0rc1 && git push --tags`) or manual via Workflow Dispatch
- **Workflow:** [`.github/workflows/wheels.yml`](.github/workflows/wheels.yml)
- **Requirement:** PyPI API token as GitHub Secret `PYPI_API_TOKEN` (Settings -> Secrets -> Actions)

### Manual
```bash
# Install dependencies
python -m pip install build twine

# Build wheel
python -m build

# Upload to PyPI
python -m twine upload dist/* --username __token__ --password $PYPI_API_TOKEN

# Upload to TestPyPI
python -m twine upload dist/* --username __token__ --password $PYPI_API_TOKEN --repository testpypi
```

---

## License
MIT - see [LICENSE](LICENSE)
