<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="virtex6" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_3" />
        <signal name="stop" />
        <signal name="in_tc" />
        <signal name="clk" />
        <port polarity="Output" name="stop" />
        <port polarity="Input" name="in_tc" />
        <port polarity="Input" name="clk" />
        <blockdef name="or2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="192" ey="-96" sx="112" sy="-48" r="88" cx="116" cy="-136" />
            <arc ex="48" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <line x2="48" y1="-144" y2="-144" x1="112" />
            <arc ex="112" ey="-144" sx="192" sy="-96" r="88" cx="116" cy="-56" />
            <line x2="48" y1="-48" y2="-48" x1="112" />
        </blockdef>
        <blockdef name="fd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <rect width="256" x="64" y="-320" height="256" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-256" y2="-256" x1="0" />
            <line x2="320" y1="-256" y2="-256" x1="384" />
            <line x2="64" y1="-128" y2="-144" x1="80" />
            <line x2="80" y1="-112" y2="-128" x1="64" />
        </blockdef>
        <block symbolname="or2" name="XLXI_1">
            <blockpin signalname="stop" name="I0" />
            <blockpin signalname="in_tc" name="I1" />
            <blockpin signalname="XLXN_3" name="O" />
        </block>
        <block symbolname="fd" name="XLXI_4">
            <blockpin signalname="clk" name="C" />
            <blockpin signalname="XLXN_3" name="D" />
            <blockpin signalname="stop" name="Q" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1216" y="800" name="XLXI_1" orien="R0" />
        <branch name="XLXN_3">
            <wire x2="1520" y1="704" y2="704" x1="1472" />
        </branch>
        <instance x="1520" y="960" name="XLXI_4" orien="R0" />
        <branch name="stop">
            <wire x2="1216" y1="736" y2="736" x1="1136" />
            <wire x2="1136" y1="736" y2="944" x1="1136" />
            <wire x2="1984" y1="944" y2="944" x1="1136" />
            <wire x2="1984" y1="704" y2="704" x1="1904" />
            <wire x2="1984" y1="704" y2="944" x1="1984" />
            <wire x2="2064" y1="704" y2="704" x1="1984" />
        </branch>
        <branch name="in_tc">
            <wire x2="1216" y1="672" y2="672" x1="1184" />
        </branch>
        <iomarker fontsize="28" x="1184" y="672" name="in_tc" orien="R180" />
        <branch name="clk">
            <wire x2="1520" y1="832" y2="832" x1="1488" />
        </branch>
        <iomarker fontsize="28" x="1488" y="832" name="clk" orien="R180" />
        <iomarker fontsize="28" x="2064" y="704" name="stop" orien="R0" />
    </sheet>
</drawing>