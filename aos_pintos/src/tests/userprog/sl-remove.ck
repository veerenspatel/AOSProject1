# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected ([<<'EOF']);
(sl-remove) begin
(sl-remove) create "test.txt"
(sl-remove) open "test.txt"
(sl-remove) symlink() successfully returned 0
(sl-remove) remove "test.txt" file
(sl-remove) open "test-link.txt" should fail
(sl-remove) end
sl-remove: exit(0)
EOF
pass;
