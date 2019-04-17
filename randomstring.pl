
#if((scalar @ARGV) != 1)
#{
#	print "$0 [NUMBER]\n";
#	exit;
#}


my @chars = ("A".."Z", "a".."z");
my $string;
my @range = (100000..200000);
my $num = $ARGV[0];
$string .= $chars[rand @chars] for 1..(rand @range);
print "$string";
