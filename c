import { useState, useRef, useEffect } from "react";
const JUDO_KB = {
 "сэои": `**Сэои-наге (背負投) — бросок через спину**\n\n1. **Захват**: правой рукой — рукав, "осото": `**О-сото-гари (⼤外刈) — большая внешняя подсечка**\n\n1. **Захват**: левой рукой  "ханэ": `**Хане-гоши (跳腰) — бросок через бедро прыжком**\n\n1. **Захват**: правая рука — в "утимата": `**Ути-мата (内股) — бросок с захватом между ног**\n\n1. **Вход**: повернись спин "томоэ": `**Томоэ-наге (巴投) — круговой бросок**\n\n1. **Захват**: оба отворота или воротни "тайотоши": `**Тай-отоши (体落) — бросок с подставкой тела**\n\n1. **Захват**: правая рука — "иппон": `**Иппон (⼀本) — чистая победа**\n\nИппон присуждается если:\n• Бросок **на спину* "пояс": `**Пояса в дзюдо (帯 — оби)**\n\n**Кю (ученические ступени):**\n• Белый — 6 кю (нов "начать": `**Как начать тренироваться по дзюдо?**\n\n1. **Найди клуб** — ищи секцию дзюдо и "удуш": `**Удушающие приёмы (絞め技 — симэ-вадза)**\n\n**Окури-эри-симэ** — скользящим ворот "кано": `**Дзигоро Кано (嘉納治五郎) — основатель дзюдо**\n\nКано создал дзюдо в **1882 году* "болев": `**Болевые приёмы (関節技 — кансэцу-вадза)**\n\nВ дзюдо разрешены только **болевые  "рандори": `**Рандори (乱取) — свободная тренировка**\n\nРандори — сердце тренировки дзюдо,  "укеми": `**Укеми (受け身) — техника безопасного падения**\n\nУкеми — первое, что учат в дзю "осаэкоми": `**Осаэкоми (抑込) — удержание**\n\nУдержание засчитывается когда:\n• Соперник п "олимп": `**Дзюдо на Олимпийских играх**\n\nДзюдо дебютировало на **Олимпиаде в Токио в 196 "история": `**История дзюдо кратко**\n\n• **1882** — Дзигоро Кано основывает Кодокан в Токи "чемпионы": `**Легенды мирового дзюдо**\n\n **Тадахиро Номура** — единственный трёхкратны};
function findAnswer(q) {
 const t = q.toLowerCase();
 if (t.match(/сэои|seoi|бросок через спину/)) return JUDO_KB["сэои"];
 if (t.match(/осото|о.сото|сото.гари|внешн.*подсеч/)) return JUDO_KB["осото"];
 if (t.match(/ханэ|хане.гоши|прыжк.*бедр/)) return JUDO_KB["ханэ"];
 if (t.match(/утимата|ути.мата|между ног/)) return JUDO_KB["утимата"];
 if (t.match(/томоэ|tomoe|круговой бросок/)) return JUDO_KB["томоэ"];
 if (t.match(/тайотоши|тай.отоши|подставк.*тел/)) return JUDO_KB["тайотоши"];
 if (t.match(/иппон|вазари|победа/)) return JUDO_KB["иппон"];
 if (t.match(/пояс|кю\b|дан\b|белый пояс|чёрный пояс|черный пояс/)) return JUDO_KB["пояс"];
 if (t.match(/начать|начало|новичок|первый раз|с чего|как записат/)) return JUDO_KB["начать" if (t.match(/удуш|симэ|горло/)) return JUDO_KB["удуш"];
 if (t.match(/кано|основател|принцип/)) return JUDO_KB["кано"];
 if (t.match(/болев|локоть|рычаг|кансэцу/)) return JUDO_KB["болев"];
 if (t.match(/рандори|спарринг|свободн/)) return JUDO_KB["рандори"];
 if (t.match(/укеми|падени|упасть/)) return JUDO_KB["укеми"];
 if (t.match(/осаэкоми|удержани/)) return JUDO_KB["осаэкоми"];
 if (t.match(/олимп/)) return JUDO_KB["олимп"];
 if (t.match(/истори|кодокан|когда появил/)) return JUDO_KB["история"];
 if (t.match(/чемпион|легенд|известн|ринер|номура|тани/)) return JUDO_KB["чемпионы"];
 return null;
}
const SUGG = [
 "Как делать Сэои-наге?",
 "Что такое О-сото-гари?",
 "Объясни бросок Хане-гоши",
 "Что такое Ути-мата?",
 "Как делать Томоэ-наге?",
 "Бросок Тай-отоши",
 "Что такое Иппон?",
 "Как начать заниматься?",
 "Удушающие приёмы",
 "Пояса в дзюдо",
 "Принципы Кано",
 "Когда дзюдо появилось на Олимпиаде?",
 "История дзюдо кратко",
 "Самые известные дзюдоисты мира",
 "Что такое Рандори?",
 "Укеми — техника падений",
];
function Msg({ text }) {
 return (
 <div>
 {text.split("\n").map((line, i) => {
 const parts = line.split(/\*\*(.*?)\*\*/g);
 return (
 <p key={i} style={{ margin:"3px 0", lineHeight:1.65 }}>
 {parts.map((p, j) => j % 2 === 1 ? <strong key={j}>{p}</strong> : p)}
 </p>
 );
 })}
 </div>
 );
}
export default function App() {
 const [msgs, setMsgs] = useState([{ role:"assistant", content:"Я — Сенсей Кодокан, твой ИИ- const [input, setInput] = useState("");
 const [loading, setLoading] = useState(false);
 const [showChips, setShowChips] = useState(true);
 const endRef = useRef(null);
 const taRef = useRef(null);
 useEffect(() => { endRef.current?.scrollIntoView({ behavior:"smooth" }); }, [msgs, loading] async function send(txt) {
 const text = (txt || input).trim();
 if (!text || loading) return;
 setInput(""); setShowChips(false);
 const next = [...msgs, { role:"user", content:text }];
 setMsgs(next); setLoading(true);
 const local = findAnswer(text);
 if (local) {
 await new Promise(r => setTimeout(r, 500));
 setMsgs([...next, { role:"assistant", content:local }]);
 setLoading(false); return;
 }
 try {
 const r = await fetch("https://api.anthropic.com/v1/messages", {
 method:"POST",
 headers:{"Content-Type":"application/json"},
 body: JSON.stringify({
 model:"claude-sonnet-4-20250514", max_tokens:1000,
 system:"Ты — Сенсей Кодокан, профессиональный тренер и эксперт по дзюдо. Отвечай по messages: next.map(m => ({ role:m.role, content:m.content })),
 }),
 });
 const d = await r.json();
 setMsgs([...next, { role:"assistant", content: d?.content?.[0]?.text || "Не получил отв } catch {
 setMsgs([...next, { role:"assistant", content:"Осс! Нет связи с сервером прямо сейчас.  }
 setLoading(false);
 }
 return (
 <div style={S.root}>
 <div style={S.grid}/>
 <header style={S.hdr}>
 <div style={S.hIn}>
 <span style={S.knji}>柔</span>
 <div>
 <div style={S.ttl}>Сенсей Кодокан</div>
 <div style={S.sub}>ИИ-тренер по дзюдо</div>
 </div>
 </div>
 </header>
 <main style={S.main}>
 {msgs.map((m,i)=>(
 <div key={i} style={{...S.row,justifyContent:m.role==="user"?"flex-end":"flex-start {m.role==="assistant"&&<div style={S.ava}>柔</div>}
 <div style={{...S.bbl,...(m.role==="user"?S.bU:S.bB)}}>
 {m.role==="assistant"?<Msg text={m.content}/>:m.content}
 </div>
 </div>
 ))}
 {loading&&(
 <div style={{...S.row,justifyContent:"flex-start"}}>
 <div style={S.ava}>柔</div>
 <div style={{...S.bbl,...S.bB,padding:"14px 18px",display:"flex",gap:6}}>
 {[0,.2,.4].map((d,i)=><span key={i} style={{animation:`blink 1.2s ${d}s infinit </div>
 </div>
 )}
 <div ref={endRef}/>
 </main>
 {showChips&&(
 <div style={S.chips}>
 {SUGG.map((s,i)=>(
 <button key={i} style={S.chip} onClick={()=>send(s)}>{s}</button>
 ))}
 </div>
 )}
 <footer style={S.foot}>
 <div style={S.iRow}>
 <textarea ref={taRef} value={input} onChange={e=>setInput(e.target.value)}
 onKeyDown={e=>{if(e.key==="Enter"&&!e.shiftKey){e.preventDefault();send();}}}
 placeholder="Задай вопрос сенсею..." style={S.ta} rows={1} disabled={loading}/>
 <button onClick={()=>send()} disabled={!input.trim()||loading}
 style={{...S.btn,opacity:(!input.trim()||loading)?.4:1}}>投</button>
 </div>
 <div style={S.note}>Основа дзюдо — уважение и готовность к обучению </div>
 </footer>
 <style>{`
 @import url('https://fonts.googleapis.com/css2?family=Noto+Serif+JP:wght@700&family=I *{box-sizing:border-box;margin:0;padding:0}
 @keyframes blink{0%,100%{opacity:.15}50%{opacity:1}}
 textarea:focus{outline:none;border-color:rgba(212,137,42,.7)!important}
 button:hover:not(:disabled){filter:brightness(1.12)}
 ::-webkit-scrollbar{width:5px}::-webkit-scrollbar-thumb{background:rgba(180,120,60,.3 `}</style>
 </div>
 );
}
const S = {
 root:{fontFamily:"'Inter',sans-serif",height:"100vh",display:"flex",flexDirection:"column", grid:{position:"absolute",inset:0,backgroundImage:"repeating-linear-gradient(0deg,rgba(180, hdr:{background:"rgba(8,4,0,.97)",borderBottom:"1px solid rgba(180,120,60,.22)",padding:"12 hIn:{maxWidth:720,margin:"0 auto",display:"flex",alignItems:"center",gap:12},
 knji:{fontFamily:"'Noto Serif JP',serif",fontSize:33,color:"#d4892a",textShadow:"0 0 20px r ttl:{fontFamily:"'Noto Serif JP',serif",fontSize:17,fontWeight:700,color:"#f5e6c8"},
 sub:{fontSize:11,color:"rgba(212,137,42,.75)",marginTop:2},
 blts:{marginLeft:"auto",display:"flex",gap:5},
 bd:{width:11,height:11,borderRadius:"50%",boxShadow:"0 0 5px rgba(255,255,255,.12)"},
 main:{flex:1,overflowY:"auto",padding:"16px 14px",zIndex:1,position:"relative",display:"fle row:{display:"flex",alignItems:"flex-end",gap:9},
 ava:{fontFamily:"'Noto Serif JP',serif",width:34,height:34,borderRadius:"50%",background:"l bbl:{maxWidth:"78%",padding:"11px 15px",borderRadius:16,fontSize:13.5},
 bB:{background:"rgba(28,14,3,.92)",border:"1px solid rgba(180,120,60,.18)",color:"#f5e6c8", bU:{background:"linear-gradient(135deg,#7a3c10,#bf7525)",color:"#fff",borderBottomRightRadi chips:{zIndex:2,padding:"0 14px 10px",display:"flex",flexWrap:"wrap",gap:7,maxWidth:720,mar chip:{background:"rgba(28,14,3,.85)",border:"1px solid rgba(180,120,60,.32)",color:"#d4892a foot:{borderTop:"1px solid rgba(180,120,60,.18)",background:"rgba(6,3,0,.98)",padding:"12px iRow:{maxWidth:720,margin:"0 auto",display:"flex",gap:9,alignItems:"flex-end"},
 ta:{flex:1,background:"rgba(28,14,3,.9)",border:"1px solid rgba(180,120,60,.25)",borderRadi btn:{fontFamily:"'Noto Serif JP',serif",width:46,height:46,borderRadius:12,background:"line note:{textAlign:"center",fontSize:11,color:"rgba(180,120,60,.4)",marginTop:7,ma
