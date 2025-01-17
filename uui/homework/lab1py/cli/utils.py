import os.path
from argparse import ArgumentParser


def is_valid_file(parser: ArgumentParser, arg: str):
    if not os.path.exists(arg):
        parser.error("The file %s does not exist!" % arg)
    else:
        return open(arg, 'r')