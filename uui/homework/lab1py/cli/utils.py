import os.path
from argparse import ArgumentParser


def is_valid_file(parser: ArgumentParser, arg: str):
    """Checks if the file exists.
    
    Args:
        parser: The parser object (from argparse).
        arg: The argument to check (file path).
    
    Returns:
        The opened file.
    
    The program exits with an error if the file does not exist.
    """

    if not os.path.exists(arg):
        parser.error("The file %s does not exist!" % arg)
    else:
        return open(arg, 'r')