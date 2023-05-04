import pyclip
import argparse

replace_dict = {'$'  : '$\\$$',
                '{'  : '$\\{$',
                '}'  : '$\\}$',
                '%'  : '$\\%$',
                '&'  : '$\\&$',
                '#'  : '$\\#$',
                '<'  : '$<$',
                '>'  : '$>$',
                '\n' : '',
                '  ' : '\\tab ',
                '\t' : '\\tab ',
                '_'  : '$\\_$',
                '^'  : '\\string^'}
parser = argparse.ArgumentParser(description='file to copy')
parser.add_argument('-f', '--file', type=str, help='Path to the file')
args = parser.parse_args()

def replace_chars(text, replace_dict):
    for old, new in replace_dict.items():
        text = text.replace(old, new)
    return text

def main():
    try:
        with open(args.file, 'r') as file:
            line = file.readline()
            index = 1
            result = '\\begin{tabular}{c|l}\n'
            while line:
                proc_line = str(index) + ' & {\\csfont{' + replace_chars(line, replace_dict) + '}} \\\\\n'
                line = file.readline()
                index += 1
                result += '  '
                result += proc_line
            result += '\\end{tabular}\n'
            pyclip.copy(result)
    except FileNotFoundError:
        print('File', args.file, 'Not found')

if __name__ == '__main__':
    main()
