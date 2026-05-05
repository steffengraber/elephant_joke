# Elephant Joke

A minimal CMake + Python example project using scikit-build-core.

> **Hinweis:** Dies ist eine kleine Testversion. Hier wird das Verhalten von dynamischer Versionierung auf PyPI getestet.

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

## Deployment

> **Hinweis:** Dies ist eine von Mistral Vibe codierte Lösung. Der Upload zu PyPI erfolgt automatisch über GitHub Actions bei Tag-Push oder manuell per Workflow-Dispatch (siehe `.github/workflows/wheels.yml`).

**Voraussetzung für CI-Deployment:**
- PyPI API Token als GitHub Secret `PYPI_API_TOKEN` hinterlegen (Settings → Secrets and variables → Actions)

Manual upload to PyPI:
```bash
python -m pip install build twine
python -m build
python -m twine upload dist/* --username __token__ --password YOUR_PYPI_API_TOKEN
```

Test-PyPI verwenden:
```bash
python -m twine upload dist/* --username __token__ --password YOUR_TESTPYPI_API_TOKEN --repository testpypi
```
