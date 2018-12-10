#include "ht_identifier.h"
#include "ht_token.h"
#include "../utils/string_switch.h"

namespace newtoo
{

	ht_identifier identify(std::string namestr, bool& is_inline_field, short& flag_field)
	{
		if ((ht_flag)flag_field == ht_flag_not_a_tag)
			return ht_id_text;

		for (size_t i = 0; i < namestr.size(); i++)
			namestr[i] = tolower(namestr[i]);

		while (namestr.length() > 9)
			namestr = namestr.erase(0, 1);

		/* Ќекоторые названи€ пришлось обрезать до 9 символов,
		   среза€ первые буквы, воизбежании коллизии
		*/

		string_switch(namestr)
		{
			string_case("a") : { is_inline_field = true; return ht_id_tag_a; break; }
			string_case("abbr") : { return ht_id_tag_abbr; break; }
			string_case("address") : { is_inline_field = true; return ht_id_tag_address; break; }
			string_case("area") : { return ht_id_tag_area; break; }
			string_case("article") : { return ht_id_tag_article; break; }
			string_case("aside") : { return ht_id_tag_aside; break; }
			string_case("audio") : { return ht_id_tag_audio; break; }
			string_case("b") : { is_inline_field = true; return ht_id_tag_b; break; }
			string_case("base") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_base; break; }
			string_case("bdi") : { return ht_id_tag_bdi; break; }
			string_case("bdo") : { return ht_id_tag_bdo; break; }
			string_case("lockquote") : { return ht_id_tag_blockquote; break; }
			string_case("body") : { return ht_id_tag_body; break; }
			string_case("br") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_br; break; }
			string_case("button") : { return ht_id_tag_button; break; }
			string_case("canvas") : { return ht_id_tag_canvas; break; }
			string_case("caption") : { return ht_id_tag_caption; break; }
			string_case("center") : { return ht_id_tag_center; break; }
			string_case("cite") : { return ht_id_tag_cite; break; }
			string_case("code") : { return ht_id_tag_code; break; }
			string_case("col") : { return ht_id_tag_col; break; }
			string_case("colgroup") : { return ht_id_tag_colgroup; break; }
			string_case("datalist") : { return ht_id_tag_datalist; break; }
			string_case("dd") : { return ht_id_tag_dd; break; }
			string_case("del") : { return ht_id_tag_del; break; }
			string_case("details") : { return ht_id_tag_details; break; }
			string_case("dfn") : { return ht_id_tag_dfn; break; }
			string_case("dialog") : { return ht_id_tag_dialog; break; }
			string_case("div") : { return ht_id_tag_div; break; }
			string_case("dl") : { return ht_id_tag_dl; break; }
			string_case("dt") : { return ht_id_tag_dt; break; }
			string_case("em") : { return ht_id_tag_em; break; }
			string_case("embed") : { return ht_id_tag_embed; break; }
			string_case("fieldset") : { return ht_id_tag_fieldset; break; }
			string_case("igcaption") : { return ht_id_tag_figcaption; break; }
			string_case("figure") : { return ht_id_tag_figure; break; }
			string_case("footer") : { return ht_id_tag_footer; break; }
			string_case("form") : { return ht_id_tag_form; break; }
			string_case("h1") : { is_inline_field = true; return ht_id_tag_h1; break; }
			string_case("h2") : { is_inline_field = true; return ht_id_tag_h2; break; }
			string_case("h3") : { is_inline_field = true; return ht_id_tag_h3; break; }
			string_case("h4") : { is_inline_field = true; return ht_id_tag_h4; break; }
			string_case("h5") : { is_inline_field = true; return ht_id_tag_h5; break; }
			string_case("h6") : { is_inline_field = true; return ht_id_tag_h6; break; }
			string_case("head") : { return ht_id_tag_head; break; }
			string_case("header") : { return ht_id_tag_header; break; }
			string_case("hgroup") : { return ht_id_tag_hgroup; break; }
			string_case("hr") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_hr; break; }
			string_case("html") : { return ht_id_tag_html; break; }
			string_case("i") : { is_inline_field = true; return ht_id_tag_i; break; }
			string_case("iframe") : { return ht_id_tag_iframe; break; }
			string_case("img") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_img; break; }
			string_case("input") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_input; break; }
			string_case("ins") : { return ht_id_tag_ins; break; }
			string_case("kbd") : { return ht_id_tag_kbd; break; }
			string_case("label") : { is_inline_field = true; return ht_id_tag_label; break; }
			string_case("legend") : { return ht_id_tag_legend; break; }
			string_case("li") : { flag_field = (ht_flag)ht_flag_close_self_auto; return ht_id_tag_li; break; }
			string_case("link") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_link; break; }
			string_case("map") : { return ht_id_tag_map; break; }
			string_case("mark") : { return ht_id_tag_mark; break; }
			string_case("menu") : { return ht_id_tag_menu; break; }
			string_case("meta") : { flag_field = (ht_flag)ht_flag_close_self; return ht_id_tag_meta; break; }
			string_case("meter") : { return ht_id_tag_meter; break; }
			string_case("nav") : { return ht_id_tag_nav; break; }
			string_case("noscript") : { return ht_id_tag_noscript; break; }
			string_case("object") : { return ht_id_tag_object; break; }
			string_case("ol") : { return ht_id_tag_ol; break; }
			string_case("optgroup") : { return ht_id_tag_optgroup; break; }
			string_case("option") : { return ht_id_tag_option; break; }
			string_case("output") : { return ht_id_tag_output; break; }
			string_case("p") : { flag_field = (ht_flag)ht_flag_close_self_auto; return ht_id_tag_p; break; }
			string_case("param") : { return ht_id_tag_param; break; }
			string_case("pre") : { is_inline_field = true; return ht_id_tag_pre; break; }
			string_case("progress") : { return ht_id_tag_progress; break; }
			string_case("q") : { return ht_id_tag_q; break; }
			string_case("rp") : { return ht_id_tag_rp; break; }
			string_case("rt") : { return ht_id_tag_rt; break; }
			string_case("ruby") : { return ht_id_tag_ruby; break; }
			string_case("s") : { is_inline_field = true; return ht_id_tag_s; break; }
			string_case("samp") : { return ht_id_tag_samp; break; }
			string_case("script") : { return ht_id_tag_script; break; }
			string_case("section") : { return ht_id_tag_section; break; }
			string_case("select") : { return ht_id_tag_select; break; }
			string_case("small") : { return ht_id_tag_small; break; }
			string_case("source") : { return ht_id_tag_source; break; }
			string_case("span") : { is_inline_field = true; return ht_id_tag_span; break; }
			string_case("strike") : { is_inline_field = true; return ht_id_tag_strike; break; }
			string_case("strong") : { is_inline_field = true; return ht_id_tag_strong; break; }
			string_case("style") : { return ht_id_tag_style; break; }
			string_case("sub") : { is_inline_field = true; return ht_id_tag_sub; break; }
			string_case("summary") : { return ht_id_tag_summary; break; }
			string_case("sup") : { is_inline_field = true; return ht_id_tag_sup; break; }
			string_case("table") : { return ht_id_tag_table; break; }
			string_case("tbody") : { return ht_id_tag_tbody; break; }
			string_case("td") : { return ht_id_tag_td; break; }
			string_case("textarea") : { return ht_id_tag_textarea; break; }
			string_case("tfoot") : { return ht_id_tag_tfoot; break; }
			string_case("th") : { return ht_id_tag_th; break; }
			string_case("thead") : { return ht_id_tag_thead; break; }
			string_case("time") : { return ht_id_tag_time; break; }
			string_case("title") : { return ht_id_tag_title; break; }
			string_case("tr") : { return ht_id_tag_tr; break; }
			string_case("track") : { return ht_id_tag_track; break; }
			string_case("u") : { is_inline_field = true; return ht_id_tag_u; break; }
			string_case("ul") : { return ht_id_tag_ul; break; }
			string_case("var") : { return ht_id_tag_var; break; }
			string_case("video") : { return ht_id_tag_video; break; }
			string_case("altglyph") : { return ht_id_tag_altGlyph; break; }
			string_case("tglyphdef") : { return ht_id_tag_altGlyphDef; break; }
			string_case("glyphitem") : { return ht_id_tag_altGlyphItem; break; }
			string_case("animate") : { return ht_id_tag_animate; break; }
			string_case("matecolor") : { return ht_id_tag_animateColor; break; }
			string_case("atemotion") : { return ht_id_tag_animateMotion; break; }
			string_case("transform") : { return ht_id_tag_animateTransform; break; }
			string_case("circle") : { return ht_id_tag_circle; break; }
			string_case("clipPath") : { return ht_id_tag_clipPath; break; }
			string_case("cursor") : { return ht_id_tag_cursor; break; }
			string_case("defs") : { return ht_id_tag_defs; break; }
			string_case("desc") : { return ht_id_tag_desc; break; }
			string_case("discard") : { return ht_id_tag_discard; break; }
			string_case("ellipse") : { return ht_id_tag_ellipse; break; }
			string_case("feblend") : { return ht_id_tag_feBlend; break; }
			string_case("lormatrix") : { return ht_id_tag_feColorMatrix; break; }
			string_case("ttransfer") : { return ht_id_tag_feComponentTransfer; break; }
			string_case("composite") : { return ht_id_tag_feComposite; break; }
			string_case("lvematrix") : { return ht_id_tag_feConvolveMatrix; break; }
			string_case("elighting") : { return ht_id_tag_feDiffuseLighting; break; }
			string_case("cementMap") : { return ht_id_tag_feDisplacementMap; break; }
			string_case("tantlight") : { return ht_id_tag_feDistantLight; break; }
			string_case("feflood") : { return ht_id_tag_feFlood; break; }
			string_case("fefunca") : { return ht_id_tag_feFuncA; break; }
			string_case("fefuncb") : { return ht_id_tag_feFuncB; break; }
			string_case("fefuncg") : { return ht_id_tag_feFuncG; break; }
			string_case("fefuncr") : { return ht_id_tag_feFuncR; break; }
			string_case("ssianblur") : { return ht_id_tag_feGaussianBlur; break; }
			string_case("feimage") : { return ht_id_tag_feImage; break; }
			string_case("femerge") : { return ht_id_tag_feMerge; break; }
			string_case("mergenode") : { return ht_id_tag_feMergeNode; break; }
			string_case("orphology") : { return ht_id_tag_feMorphology; break; }
			string_case("feoffset") : { return ht_id_tag_feOffset; break; }
			string_case("ointlight") : { return ht_id_tag_fePointLight; break; }
			string_case("rlighting") : { return ht_id_tag_feSpecularLighting; break; }
			string_case("spotlight") : { return ht_id_tag_feSpotLight; break; }
			string_case("fetile") : { return ht_id_tag_feTile; break; }
			string_case("urbulence") : { return ht_id_tag_feTurbulence; break; }
			string_case("filter") : { return ht_id_tag_filter; break; }
			string_case("font") : { return ht_id_tag_font; break; }
			string_case("ignobject") : { return ht_id_tag_foreignObject; break; }
			string_case("g") : { return ht_id_tag_g; break; }
			string_case("glyph") : { return ht_id_tag_glyph; break; }
			string_case("glyphref") : { return ht_id_tag_glyphRef; break; }
			string_case("hatch") : { return ht_id_tag_hatch; break; }
			string_case("hatchpath") : { return ht_id_tag_hatchpath; break; }
			string_case("hkern") : { return ht_id_tag_hkern; break; }
			string_case("image") : { return ht_id_tag_image; break; }
			string_case("line") : { return ht_id_tag_line; break; }
			string_case("rgradient") : { return ht_id_tag_linearGradient; break; }
			string_case("marker") : { return ht_id_tag_marker; break; }
			string_case("mask") : { return ht_id_tag_mask; break; }
			string_case("mesh") : { return ht_id_tag_mesh; break; }
			string_case("hgradient") : { return ht_id_tag_meshgradient; break; }
			string_case("meshpatch") : { return ht_id_tag_meshpatch; break; }
			string_case("meshrow") : { return ht_id_tag_meshrow; break; }
			string_case("metadata") : { return ht_id_tag_metadata; break; }
			string_case("mpath") : { return ht_id_tag_mpath; break; }
			string_case("path") : { return ht_id_tag_path; break; }
			string_case("pattern") : { return ht_id_tag_pattern; break; }
			string_case("polygon") : { return ht_id_tag_polygon; break; }
			string_case("polyline") : { return ht_id_tag_polyline; break; }
			string_case("lgradient") : { return ht_id_tag_radialGradient; break; }
			string_case("rect") : { return ht_id_tag_rect; break; }
			string_case("set") : { return ht_id_tag_set; break; }
			string_case("olidcolor") : { return ht_id_tag_solidcolor; break; }
			string_case("stop") : { return ht_id_tag_stop; break; }
			string_case("svg") : { return ht_id_tag_svg; break; }
			string_case("switch") : { return ht_id_tag_switch; break; }
			string_case("symbol") : { return ht_id_tag_symbol; break; }
			string_case("text") : { return ht_id_tag_text; break; }
			string_case("textPath") : { return ht_id_tag_textPath; break; }
			string_case("tref") : { return ht_id_tag_tref; break; }
			string_case("tspan") : { return ht_id_tag_tspan; break; }
			string_case("unknown") : { return ht_id_tag_unknown; break; }
			string_case("use") : { return ht_id_tag_use; break; }
			string_case("view") : { return ht_id_tag_view; break; }
			string_case("vkern") : { return ht_id_tag_vkern; break; }

			string_case("!doctype") : { return ht_id_document_type; break; }
			string_case("!--") : { return ht_id_comment; break; }

			default : { return ht_id_tag__undefined; break; }
		}

		return ht_id_tag__undefined;
	}

	std::string ht_identifier_to_string(ht_identifier id) {

		switch (id)
		{
			case ht_id_text: { return "#text"; break; }
			case ht_id_comment: { return "#comment"; break; }
			case ht_id_document_type: { return "#document_type"; break; }
			case ht_id_tag__undefined: { return "_undefined"; break; }

			case ht_id_tag_abbr: { return "abbr"; break; }
			case ht_id_tag_address: { return "address"; break; }
			case ht_id_tag_area: { return "area"; break; }
			case ht_id_tag_article: { return "article"; break; }
			case ht_id_tag_aside: { return "aside"; break; }
			case ht_id_tag_audio: { return "audio"; break; }
			case ht_id_tag_b: { return "b"; break; }
			case ht_id_tag_base: { return "base"; break; }
			case ht_id_tag_bdi: { return "bdi"; break; }
			case ht_id_tag_bdo: { return "bdo"; break; }
			case ht_id_tag_blockquote: { return "blockquote"; break; }
			case ht_id_tag_body: { return "body"; break; }
			case ht_id_tag_br: { return "br"; break; }
			case ht_id_tag_button: { return "button"; break; }
			case ht_id_tag_canvas: { return "canvas"; break; }
			case ht_id_tag_caption: { return "caption"; break; }
			case ht_id_tag_center: { return "center"; break; }
			case ht_id_tag_cite: { return "cite"; break; }
			case ht_id_tag_code: { return "code"; break; }
			case ht_id_tag_col: { return "col"; break; }
			case ht_id_tag_colgroup: { return "colgroup"; break; }
			case ht_id_tag_datalist: { return "datalist"; break; }
			case ht_id_tag_dd: { return "dd"; break; }
			case ht_id_tag_del: { return "del"; break; }
			case ht_id_tag_details: { return "details"; break; }
			case ht_id_tag_dfn: { return "dfn"; break; }
			case ht_id_tag_dialog: { return "dialog"; break; }
			case ht_id_tag_div: { return "div"; break; }
			case ht_id_tag_dl: { return "dl"; break; }
			case ht_id_tag_dt: { return "dt"; break; }
			case ht_id_tag_em: { return "em"; break; }
			case ht_id_tag_embed: { return "embed"; break; }
			case ht_id_tag_fieldset: { return "fieldset"; break; }
			case ht_id_tag_figcaption: { return "figcaption"; break; }
			case ht_id_tag_figure: { return "figure"; break; }
			case ht_id_tag_footer: { return "footer"; break; }
			case ht_id_tag_form: { return "form"; break; }
			case ht_id_tag_h1: { return "h1"; break; }
			case ht_id_tag_h2: { return "h2"; break; }
			case ht_id_tag_h3: { return "h3"; break; }
			case ht_id_tag_h4: { return "h4"; break; }
			case ht_id_tag_h5: { return "h5"; break; }
			case ht_id_tag_h6: { return "h6"; break; }
			case ht_id_tag_head: { return "head"; break; }
			case ht_id_tag_header: { return "header"; break; }
			case ht_id_tag_hgroup: { return "hgroup"; break; }
			case ht_id_tag_hr: { return "hr"; break; }
			case ht_id_tag_html: { return "html"; break; }
			case ht_id_tag_i: { return "i"; break; }
			case ht_id_tag_iframe: { return "iframe"; break; }
			case ht_id_tag_img: { return "img"; break; }
			case ht_id_tag_input: { return "input"; break; }
			case ht_id_tag_ins: { return "ins"; break; }
			case ht_id_tag_kbd: { return "kbd"; break; }
			case ht_id_tag_label: { return "label"; break; }
			case ht_id_tag_legend: { return "legend"; break; }
			case ht_id_tag_li: { return "li"; break; }
			case ht_id_tag_link: { return "link"; break; }
			case ht_id_tag_map: { return "map"; break; }
			case ht_id_tag_mark: { return "mark"; break; }
			case ht_id_tag_menu: { return "menu"; break; }
			case ht_id_tag_meta: { return "meta"; break; }
			case ht_id_tag_meter: { return "meter"; break; }
			case ht_id_tag_nav: { return "nav"; break; }
			case ht_id_tag_noscript: { return "noscript"; break; }
			case ht_id_tag_object: { return "object"; break; }
			case ht_id_tag_ol: { return "ol"; break; }
			case ht_id_tag_optgroup: { return "optgroup"; break; }
			case ht_id_tag_option: { return "option"; break; }
			case ht_id_tag_output: { return "output"; break; }
			case ht_id_tag_p: { return "p"; break; }
			case ht_id_tag_param: { return "param"; break; }
			case ht_id_tag_pre: { return "pre"; break; }
			case ht_id_tag_progress: { return "progress"; break; }
			case ht_id_tag_q: { return "q"; break; }
			case ht_id_tag_rp: { return "rp"; break; }
			case ht_id_tag_rt: { return "rt"; break; }
			case ht_id_tag_ruby: { return "ruby"; break; }
			case ht_id_tag_s: { return "s"; break; }
			case ht_id_tag_samp: { return "samp"; break; }
			case ht_id_tag_script: { return "script"; break; }
			case ht_id_tag_section: { return "section"; break; }
			case ht_id_tag_select: { return "select"; break; }
			case ht_id_tag_small: { return "small"; break; }
			case ht_id_tag_source: { return "source"; break; }
			case ht_id_tag_span: { return "span"; break; }
			case ht_id_tag_strike: { return "strike"; break; }
			case ht_id_tag_strong: { return "strong"; break; }
			case ht_id_tag_style: { return "style"; break; }
			case ht_id_tag_sub: { return "sub"; break; }
			case ht_id_tag_summary: { return "summary"; break; }
			case ht_id_tag_sup: { return "sup"; break; }
			case ht_id_tag_table: { return "table"; break; }
			case ht_id_tag_tbody: { return "tbody"; break; }
			case ht_id_tag_td: { return "td"; break; }
			case ht_id_tag_textarea: { return "textarea"; break; }
			case ht_id_tag_tfoot: { return "tfoot"; break; }
			case ht_id_tag_th: { return "th"; break; }
			case ht_id_tag_thead: { return "thead"; break; }
			case ht_id_tag_time: { return "time"; break; }
			case ht_id_tag_title: { return "title"; break; }
			case ht_id_tag_tr: { return "tr"; break; }
			case ht_id_tag_track: { return "track"; break; }
			case ht_id_tag_u: { return "u"; break; }
			case ht_id_tag_ul: { return "ul"; break; }
			case ht_id_tag_var: { return "var"; break; }
			case ht_id_tag_video: { return "video"; break; }
			case ht_id_tag_altGlyph: { return "altGlyph"; break; }
			case ht_id_tag_altGlyphDef: { return "altGlyphDef"; break; }
			case ht_id_tag_altGlyphItem: { return "altGlyphItem"; break; }
			case ht_id_tag_animate: { return "animate"; break; }
			case ht_id_tag_animateColor: { return "animateColor"; break; }
			case ht_id_tag_animateMotion: { return "animateMotion"; break; }
			case ht_id_tag_animateTransform: { return "animateTransform"; break; }
			case ht_id_tag_circle: { return "circle"; break; }
			case ht_id_tag_clipPath: { return "clipPath"; break; }
			case ht_id_tag_cursor: { return "cursor"; break; }
			case ht_id_tag_defs: { return "defs"; break; }
			case ht_id_tag_desc: { return "desc"; break; }
			case ht_id_tag_discard: { return "discard"; break; }
			case ht_id_tag_ellipse: { return "ellipse"; break; }
			case ht_id_tag_feBlend: { return "feBlend"; break; }
			case ht_id_tag_feColorMatrix: { return "feColorMatrix"; break; }
			case ht_id_tag_feComponentTransfer: { return "feComponentTransfer"; break; }
			case ht_id_tag_feComposite: { return "feComposite"; break; }
			case ht_id_tag_feConvolveMatrix: { return "feConvolveMatrix"; break; }
			case ht_id_tag_feDiffuseLighting: { return "feDiffuseLighting"; break; }
			case ht_id_tag_feDisplacementMap: { return "feDisplacementMap"; break; }
			case ht_id_tag_feDistantLight: { return "feDistantLight"; break; }
			case ht_id_tag_feFlood: { return "feFlood"; break; }
			case ht_id_tag_feFuncA: { return "feFuncA"; break; }
			case ht_id_tag_feFuncB: { return "feFuncB"; break; }
			case ht_id_tag_feFuncG: { return "feFuncG"; break; }
			case ht_id_tag_feFuncR: { return "feFuncR"; break; }
			case ht_id_tag_feGaussianBlur: { return "feGaussianBlur"; break; }
			case ht_id_tag_feImage: { return "feImage"; break; }
			case ht_id_tag_feMerge: { return "feMerge"; break; }
			case ht_id_tag_feMergeNode: { return "feMergeNode"; break; }
			case ht_id_tag_feMorphology: { return "feMorphology"; break; }
			case ht_id_tag_feOffset: { return "feOffset"; break; }
			case ht_id_tag_fePointLight: { return "fePointLight"; break; }
			case ht_id_tag_feSpecularLighting: { return "feSpecularLighting"; break; }
			case ht_id_tag_feSpotLight: { return "feSpotLight"; break; }
			case ht_id_tag_feTile: { return "feTile"; break; }
			case ht_id_tag_feTurbulence: { return "feTurbulence"; break; }
			case ht_id_tag_filter: { return "filter"; break; }
			case ht_id_tag_font: { return "font"; break; }
			case ht_id_tag_foreignObject: { return "foreignObject"; break; }
			case ht_id_tag_g: { return "g"; break; }
			case ht_id_tag_glyph: { return "glyph"; break; }
			case ht_id_tag_glyphRef: { return "glyphRef"; break; }
			case ht_id_tag_hatch: { return "hatch"; break; }
			case ht_id_tag_hatchpath: { return "hatchpath"; break; }
			case ht_id_tag_hkern: { return "hkern"; break; }
			case ht_id_tag_image: { return "image"; break; }
			case ht_id_tag_line: { return "line"; break; }
			case ht_id_tag_linearGradient: { return "linearGradient"; break; }
			case ht_id_tag_marker: { return "marker"; break; }
			case ht_id_tag_mask: { return "mask"; break; }
			case ht_id_tag_mesh: { return "mesh"; break; }
			case ht_id_tag_meshgradient: { return "meshgradient"; break; }
			case ht_id_tag_meshpatch: { return "meshpatch"; break; }
			case ht_id_tag_meshrow: { return "meshrow"; break; }
			case ht_id_tag_metadata: { return "metadata"; break; }
			case ht_id_tag_mpath: { return "mpath"; break; }
			case ht_id_tag_path: { return "path"; break; }
			case ht_id_tag_pattern: { return "pattern"; break; }
			case ht_id_tag_polygon: { return "polygon"; break; }
			case ht_id_tag_polyline: { return "polyline"; break; }
			case ht_id_tag_radialGradient: { return "radialGradient"; break; }
			case ht_id_tag_rect: { return "rect"; break; }
			case ht_id_tag_set: { return "set"; break; }
			case ht_id_tag_solidcolor: { return "solidcolor"; break; }
			case ht_id_tag_stop: { return "stop"; break; }
			case ht_id_tag_svg: { return "svg"; break; }
			case ht_id_tag_switch: { return "switch"; break; }
			case ht_id_tag_symbol: { return "symbol"; break; }
			case ht_id_tag_text: { return "text"; break; }
			case ht_id_tag_textPath: { return "textPath"; break; }
			case ht_id_tag_tref: { return "tref"; break; }
			case ht_id_tag_tspan: { return "tspan"; break; }
			case ht_id_tag_unknown: { return "unknown"; break; }
			case ht_id_tag_use: { return "use"; break; }
			case ht_id_tag_view: { return "view"; break; }
			case ht_id_tag_vkern: { return "vkern"; break; }
		}
		return "_undefined";
	}
}
