#include "doctest/doctest.h"
#include <string>
#include <vector>

// begin-snippet: fmt_includes

#include <fmt/ranges.h>
// end-snippet

#include "ApprovalTests/integrations/fmt/FmtApprovals.h"

using namespace ApprovalTests;

TEST_CASE("FmtContainers")
{
    // begin-snippet: fmt_approvals
    std::vector<int> numbers = {1, 2, 3};
    FmtApprovals::verify(numbers);
    // end-snippet
}
