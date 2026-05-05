# Elephant Joke

A minimal CMake + Python example project using scikit-build-core.

## Installation

```bash
pip install .
```

## Usage

```python
from elephant_joke import elephant_joke
print(elephant_joke())
```

## Version

The package version is dynamically read from the `VERSION` file using regex transformation:
- `3.10_rc2` → `3.10rc2`
- `3.10_dev1` → `3.10.dev1`

## Testing

Build and install in development mode:
```bash
pip install -e .
```

Test the package:
```bash
python -c "from elephant_joke import elephant_joke, __version__; print(f'v{__version__}: {elephant_joke()}')"
```

Build a wheel:
```bash
pip wheel . --no-deps
```

Install from wheel:
```bash
pip install elephant_joke-*.whl
```
