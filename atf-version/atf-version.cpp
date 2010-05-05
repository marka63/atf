//
// Automated Testing Framework (atf)
//
// Copyright (c) 2007, 2008, 2009 The NetBSD Foundation, Inc.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND
// CONTRIBUTORS ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
// INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
// GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
// IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
// IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#if defined(HAVE_CONFIG_H)
#include "bconfig.h"
#endif
#include "atf-version/revision.h"

#include <cstdlib>
#include <iostream>

#include "atf-c++/application.hpp"
#include "atf-c++/ui.hpp"

class atf_version : public atf::application::app {
    static const char* m_description;

public:
    atf_version(void);

    int main(void);
};

const char* atf_version::m_description =
    "atf-version is a tool that shows information about the currently "
    "installed version of ATF.";

atf_version::atf_version(void) :
    app(m_description, "atf-version(1)", "atf(7)")
{
}

int
atf_version::main(void)
{
    using atf::ui::format_text;
    using atf::ui::format_text_with_tag;

    std::cout << PACKAGE_STRING " (" PACKAGE_TARNAME "-" PACKAGE_VERSION
                 ")" << std::endl
              << PACKAGE_COPYRIGHT << std::endl
              << std::endl;

    std::cout << format_text_with_tag(PACKAGE_REVISION_BRANCH, "Branch: ",
                                      false) << std::endl;
    std::cout << format_text_with_tag(PACKAGE_REVISION_BASE
#if PACKAGE_REVISION_MODIFIED
                                      " (locally modified)"
#endif
                                      , "Base revision: ", false)
              << std::endl;
#if PACKAGE_REVISION_CACHED
    std::cout << format_text("Information gathered from data cached in "
                             "distribution; further changes may have been "
                             "made.") << std::endl;
#endif

    return EXIT_SUCCESS;
}

int
main(int argc, char* const* argv)
{
    return atf_version().run(argc, argv);
}
