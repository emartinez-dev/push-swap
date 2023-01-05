from itertools import permutations
import argparse
import random
import logging as log
import subprocess

#https://stackoverflow.com/questions/9393425/python-how-to-execute-shell-commands-with-pipe-but-without-shell-true

def configure_logger(args):
	if args.verbose == "INFO":
		log.basicConfig(format="%(levelname)s: %(message)s", level=log.INFO)
	if args.verbose == "WARNING":
		log.basicConfig(format="%(levelname)s: %(message)s", level=log.WARNING)
	else:
		log.basicConfig(format="%(levelname)s: %(message)s", level=log.CRITICAL)

def printc(text, color):
    colors = {
        "red": "\033[91m",
        "green": "\033[92m",
        "yellow": "\033[93m",
        "blue": "\033[94m",
        "magenta": "\033[95m",
        "cyan": "\033[96m",
        "white": "\033[97m",
    }
    if not color in colors:
        color = "white"
    print(colors[color] + text + "\033[0m")

def test_push_swap(array_len: int, move_limit: int):
	assert array_len > 0, "Amount of numbers must be more than 0"

	ok = 0
	ko = 0
	error = 0
	more_than_limit = 0
	total_instructions = 0

	random_list = random.sample(range(array_len + 1), array_len)
	if array_len <= 6:
		perm = permutations(random_list)
	else:
		perm = set()
		for i in range(500):
			random.shuffle(random_list)
			perm.add(tuple(random_list))

	log.info(f"Sequence that will be permutated into Push_Swap\n{random_list}\n")

	for i in list(perm):
		i = list(i)
		ps_input = ' '.join(map(str, i))
		ps_output = subprocess.getoutput(f"./push_swap {ps_input} | ./checker {ps_input}")
		ps_instructions = subprocess.getoutput(f"./push_swap {ps_input}").split("\n")
		n_instructions = len(ps_instructions)
		total_instructions += n_instructions

		if ps_output == "OK":
			if n_instructions > move_limit and move_limit > 0:
				log.warning(f"{i} was sorted in more than {move_limit} "\
					f"moves. ({n_instructions} moves)")
				log.info(f"Moves: -> {' - '.join(ps_instructions)}")
				more_than_limit += 1
			else:
				ok += 1
		if ps_output == "KO":
			log.error(f"{i} has not been sorted correctly by the given instructions.")
			log.info(f"Moves: -> {' - '.join(ps_instructions)}")
			ko += 1
		if ps_output == "Error":
			# this should never happen
			log.error(f"{i} raised an error in push_swap.")
			error += 1

	total = ok + ko + error + more_than_limit
	print(f"N of tests: {total}")
	printc(f"OK: {ok}", "green")
	if ko != 0:
		printc(f"KO: {ko}", "red")
	if more_than_limit != 0:
		printc(f"Over limit: {more_than_limit}", "yellow")
	if error != 0:
		printc(f"Error: {error}", "blue")
	print("="*80)
	print(f"Size of the input: {array_len} numbers. Average number of moves: {total_instructions / total}")
	print("="*80)

parser = argparse.ArgumentParser()

parser.add_argument("-n", "--numbers",
					help="How many numbers will be passed to push_swap",
					required=True,
					type=int)
parser.add_argument("-l", "--limit", help="Maximum move limit", default=0, type=int)
parser.add_argument("-v", "--verbose", help="Log level for the tester. "\
	"WARNING gives info about incorrectly sorted sequences, and INFO also"\
	"prints the push_swap instructions for these sequences", choices=["INFO", "WARNING"], default="ERROR")

args = parser.parse_args()

configure_logger(args)
test_push_swap(args.numbers, args.limit)