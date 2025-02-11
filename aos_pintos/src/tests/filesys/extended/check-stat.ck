# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected (IGNORE_EXIT_CODES => 1, [<<'EOF']);
(check-stat) begin
(check-stat) create "yoit"
(check-stat) open "yoit"
(check-stat) return 0 from stat() call on "yoit"
(check-stat) should have 512 logical size: actual 512
(check-stat) should have 0 physical size: actual 0
(check-stat) valid inode number
(check-stat) should have 0 block: actual 0
(check-stat) end
EOF
pass;
