from elephant_joke.elephant_joke_module import elephant_joke

try:
    from importlib.metadata import version
    __version__ = version("elephant-joke")
except ImportError:
    __version__ = "unknown"

__all__ = ["elephant_joke", "__version__"]
