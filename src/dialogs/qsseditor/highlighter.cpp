/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtGui>

#include "highlighter.h"
#include "QColor"
#include "QFontDatabase"

//! [0]
Highlighter::Highlighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
	QSettings set("Rizek","Rizek Qss Editor");
//! [1]
	QColor c1(set.value("Highlighter\ColorOfLocationFormat",Qt::darkYellow).toString());
	locationFormat.setForeground(c1);
	//locationFormat.setFontWeight(QFont::Bold);
	QStringList locationKeywordPatterns;
	locationKeywordPatterns << "top" << "left" << "bottom" << "right" << "center" << "stop";
	foreach (const QString &pattern, locationKeywordPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = locationFormat;
		highlightingRules.append(rule);
	}

	QColor c2(set.value("Highlighter\ColorOfObjectFormat",Qt::blue).toString());
	objectFormat.setForeground(c2);
	//objectFormat.setFontWeight(QFont::Bold);
	QStringList objectKeywordPatterns;
	objectKeywordPatterns << "image" << "color" << ";" << "\\*" << "radius" << "style"  << "layout" << "buttons"
		<< "have" << "icons" << "font" << "margin" << "subcontrol" <<"alternate-base" << "base" << "bright-text"
		<< "button" << "button-text" <<"dark" << "highlight" << "highlighted-text" <<"light" 
		<< "link" << "link-visited" << "mid" <<"midlight" <<"shadow" <<"text" <<"window" <<"window-text"
		<< "family" << "size"<< "lineedit-password-character" << "height" << "width" << "max"
		<< "messagebox-text-interaction-flags" << "min" << "opacity" << "padding" << "paint-alternating-row-colors-for-empty-area"
		<< "show-decoration-selected" << "spacing"<< "align"<< "decoration" << "content" << "background" << "selection" << "-" << "border" << "alternate" << "gridline"
		<< "position" << "attachment" << "clip" << "origin" << "none"  << "dashed" << "dot-dash" << "dot-dot-dash" << "dotted"
		<< "double" << "groove" << "inset" << "outset" << "ridge" << "solid" << "none" << "relative" << "absolute";
	foreach (const QString &pattern, objectKeywordPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = objectFormat;
		highlightingRules.append(rule);
	}

	QColor c3(set.value("Highlighter\ColorOfFunctionFormat",Qt::darkRed).toString());
	functionFormat.setForeground(c3);
	//functionFormat.setFontWeight(QFont::Bold);
	QStringList functionKeywordPatterns;
	functionKeywordPatterns << "rgb(.*)\\b" << "qlineargradient(.*)\\b" << "url(.*)\\b" << "\\[.*\\]" << " hsv(.*)\\b"
		<< "rgba(.*)\\b" << " hsva(.*)\\b" << "repeat-x" << "repeat-y" << "repeat" << "no-repeat";
	foreach (const QString &pattern, functionKeywordPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = functionFormat;
		highlightingRules.append(rule);
	}

	QColor c4(set.value("Highlighter\ColorOfClassesFormat",Qt::darkCyan).toString());
	classesFormat.setForeground(c4);
	//classesFormat.setFontWeight(QFont::UnderlineResolved);
	QStringList classesKeywordPatterns;
	classesKeywordPatterns << "QAbstractScrollArea" << "QCheckBox" << "QColumnView" << "QComboBox" << "QDateEdit" << "QTextBrowser"
		<< "QDateTimeEdit" << "QDialog" << "QDialogButtonBox" << "QDockWidget"  <<"QDoubleSpinBox" << "QFrame" << "QGraphicsView"
		<< "QGroupBox" << "QHeaderView" << "QLabel" << "QLineEdit"  <<"QListView" << "QListWidget" << "QMainWindow"
		<< "QMenu" << "QMenuBar" << "QMessageBox" << "QProgressBar" << "QPushButton" << "QRadioButton" << "QScrollBar" << "QSizeGrip"
		<< "QSlider" << "QSpinBox" << "QSplitter" << "QStatusBar" << "QTabBar" << "QTabWidget" << "QTableView" << "QTableWidget"
		<< "QTextEdit" << "QTimeEdit" << "QToolBar" << "QToolButton" << "QToolBox" << "QToolTip" << "QTreeView" << "QTreeWidget"
		<< "QWidget" << "QPlainTextEdit" << "Spacer" << "QCommandLinkButton" << "QStackedWidget" << "QMdiArea" << "QDial" << "QCalendarWidget"
		<< "QLCDNumber" << "Line" << "QDeclarativeView" << "QWebView" << "QAbstractItemView";
	foreach (const QString &pattern, classesKeywordPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = classesFormat;
		highlightingRules.append(rule);
	}

	QColor c5(set.value("Highlighter\ColorOfValuesFormat",Qt::blue).toString());
	valuesFormat.setForeground(c5);
	//functionFormat.setFontWeight(QFont::Bold);
	QStringList valuesKeywordPatterns;
	valuesKeywordPatterns << "#[0-9A-Fa-f]{6}" << "[0-9]" << "\\+" << "\\-"  << "px" << "[0-9 ]em" << "[0-9 ]ex";
	foreach (const QString &pattern, valuesKeywordPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = valuesFormat;
		highlightingRules.append(rule);
	}

	QColor c6(set.value("Highlighter\ColorOfPseudoStatesFormat",Qt::darkMagenta).toString());
	pseudoStatesFormat.setForeground(c6);
	//functionFormat.setFontWeight(QFont::Bold);
	QStringList pseudoKeywordPatterns;
	pseudoKeywordPatterns<< ":active"<< ":adjoins-item"<< ":alternate"<< ":bottom"<< ":checked"<< ":closable"		<< ":closed"<< ":default"<< ":disabled"<< ":editable"<< ":edit-focus"<< ":enabled"		<< ":exclusive"<< ":first"<< ":flat"<< ":floatable"<< ":focus"<< ":has-children"		<< ":has-siblings"<< ":horizontal"<< ":hover"<< ":indeterminate"<< ":last"<< ":left"		<< ":maximized"<< ":middle"<< ":minimized"<< ":movable"<< ":no-frame"<< ":non-exclusive"		<< ":off"<< ":on"<< ":only-one"<< ":open"<< ":next-selected"<< ":pressed"<< ":previous-selected"		<< ":read-only"<< ":right"<< ":selected"<< ":top"<< ":unchecked"<< ":vertical"<< ":window";
	foreach (const QString &pattern, pseudoKeywordPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = pseudoStatesFormat;
		highlightingRules.append(rule);
	}

	QColor c7(set.value("Highlighter\ColorOfSubControlsFormat",Qt::darkRed).toString());
	subControlsFormat.setForeground(c7);
	//functionFormat.setFontWeight(QFont::Bold);
	QStringList subControlsPatterns;
	subControlsPatterns <<"::add-line"<<"::add-page"<<"::branch"<<"::chunk"
		<<"::close-button"<<"::corner"<<"::down-arrow"<<"::down-button"<<"::drop-down"
		<<"::float-button"<<"::groove"<<"::indicator"<<"::handle"<<"::icon"<<"::item"<<"::left-arrow"<<"::left-corner"<<"::menu-arrow"
		<<"::menu-button"<<"::menu-indicator"<<"::right-arrow"<<"::pane"<<"::right-corner"<<"::scroller"<<"::section"
		<<"::separator"<<"::sub-line"<<"::sub-page"<<"::tab"<<"::tab-bar"
		<<"::tear"<<"::tearoff"<<"::text"<<"::title"<<"::up-arrow"<<"::up-button";
	foreach (const QString &pattern, subControlsPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = subControlsFormat;
		highlightingRules.append(rule);
	}

	QColor c8(set.value("Highlighter\ColorOfColorsFormat",QColor::fromRgb(85, 170, 255)).toString());
	colorsAndFontFormat.setForeground(c8);
	//functionFormat.setFontWeight(QFont::Bold);
	QStringList colorPatterns;
	colorPatterns = QColor::colorNames();
	QFontDatabase database;
	colorPatterns += database.families();
	foreach (const QString &pattern, colorPatterns) {
		rule.pattern = QRegExp(pattern);
		rule.format = colorsAndFontFormat;
		highlightingRules.append(rule);
	}

//! [3]
	QColor c9(set.value("Highlighter\ColorOfCommentFormat", Qt::red).toString());
    singleLineCommentFormat.setForeground(c9);
    rule.pattern = QRegExp("//[^\n]*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    multiLineCommentFormat.setForeground(c9);
//! [3]

//! [4]
    quotationFormat.setForeground(Qt::darkGreen);
	//quotationFormat.setFontWeight(QFont::Bold);
    rule.pattern = QRegExp("\".*\"");
    rule.format = quotationFormat;
    highlightingRules.append(rule);
//! [4]



//! [6]
    commentStartExpression = QRegExp("/\\*");
    commentEndExpression = QRegExp("\\*/");
}
//! [6]

//! [7]
void Highlighter::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegExp expression(rule.pattern);
        int index = expression.indexIn(text);
        while (index >= 0) {
            int length = expression.matchedLength();
            setFormat(index, length, rule.format);
            index = expression.indexIn(text, index + length);
        }
    }
//! [7] //! [8]
    setCurrentBlockState(0);
//! [8]

//! [9]
    int startIndex = 0;
    if (previousBlockState() != 1)
        startIndex = commentStartExpression.indexIn(text);

//! [9] //! [10]
    while (startIndex >= 0) {
//! [10] //! [11]
        int endIndex = commentEndExpression.indexIn(text, startIndex);
        int commentLength;
        if (endIndex == -1) {
            setCurrentBlockState(1);
            commentLength = text.length() - startIndex;
        } else {
            commentLength = endIndex - startIndex
                            + commentEndExpression.matchedLength();
        }
        setFormat(startIndex, commentLength, multiLineCommentFormat);
        startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
    }
}
//! [11]
