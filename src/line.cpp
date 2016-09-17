#include "line.h"
#include "parser.h"

extern void yyerror(const char*);

Line::Line() : org_line(0), opcode(OPCode::NONE), labels(nullptr), dst(nullptr), src(nullptr) {}
Line::Line(uint32_t org_line, Labels* labels, Argument* dst, Argument* src) :
        org_line(org_line), opcode(OPCode::NONE), labels(labels), dst(dst), src(src) {}

Line::~Line() {
    delete labels;
    delete dst;
    delete src;
}

void Line::setOPCode(ArgVal* val) {
    if(val == nullptr || val->isNum()) {
        opcode = OPCode::NONE;
        yyerror("Invalid opcode");
        return;
    }

    try {
        opcode = OPCodeFromString(*val->getStr());
    } catch(std::invalid_argument& e) {
        yyerror(e.what());
    }
}

void Line::compile() {
    //TODO: this
}

std::ostream& operator<<(std::ostream& out, const Line& line) {
    out << line.org_line << "| ";

    if(line.labels != nullptr)
        for(Labels::iterator i = line.labels->begin(); i != line.labels->end(); ++i)
            out << *i << ": ";

    out << line.opcode << " ";
    out << *line.dst;
    if(line.src != nullptr)
        out << ", " << *line.src;
    return out;
}