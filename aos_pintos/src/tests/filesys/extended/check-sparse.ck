# -*- perl -*-
use strict;
use warnings;
use tests::tests;
check_expected (IGNORE_EXIT_CODES => 1, [<<'EOF']);
(check-sparse) begin
(check-sparse) create "yoit"
(check-sparse) open "yoit"
(check-sparse) return 0 from stat() call on "yoit"
(check-sparse) should have 512 logical size: actual 512
(check-sparse) should have 0 physical size: actual 0
(check-sparse) valid inode number
(check-sparse) should have 0 block: actual 0
(check-sparse) write random bytes to "yoit"
(check-sparse) return 0 from stat() call on "yoit"
(check-sparse) should have 512 logical size: actual 512
(check-sparse) should have 500 physical size: actual 500
(check-sparse) valid inode number
(check-sparse) should have 1 block: actual 1
(check-sparse) end
EOF
pass;
