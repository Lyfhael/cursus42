#!/usr/bin/perl

print "Enter a string: ";
chomp(my $input = <STDIN>);

if ($input eq reverse($input)) {
	print "The string is a palindrome!\n";
}
else {
	print "The string is not a palindrome.\n";
}
