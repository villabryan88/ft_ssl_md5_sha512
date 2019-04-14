
if((scalar @ARGV) != 1)
{
	print "$0 [NUMBER]\n";
	exit;
}


my @chars = ("A".."Z", "a".."z");
my $string;
my $num = $ARGV[0];
$string .= $chars[rand @chars] for 1..$num;
print "$string";
