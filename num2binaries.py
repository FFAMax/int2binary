import sys
import argparse


def binary(num):
    result = []
    mask = 1
    while num > 0:
        if num & mask:
            result.append(mask)
            num -= mask
        mask <<= 1
    return result


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("-f", "--file", help="input file name")
    args = parser.parse_args()

    if args.file:
        with open(args.file, 'r') as f:
            for line in f:
                line = line.strip()
                try:
                    num = int(line)
                    result = binary(num)
                    print(result)
                except ValueError:
                    print(f"Warning: {line} is not a number", file=sys.stderr)
    else:
        for line in sys.stdin:
            line = line.strip()
            try:
                num = int(line)
                result = binary(num)
                print(result)
            except ValueError:
                print(f"Warning: {line} is not a number", file=sys.stderr)


if __name__ == "__main__":
    main()

