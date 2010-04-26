#!/usr/bin/perl -w
use strict;

print "<UL>\n";
foreach my $file (@ARGV) {
  my $nameonly = $file;
  $nameonly =~ s/.*cellml\///;
  print "  <LI> <A HREF=\"$file\">$nameonly</a></LI>\n";
}
print "</UL>\n";
