open Graphql_lwt;
open GraphqlHelpers;

type t = {
  id: int,
  email: string,
  message: string,
};

let resolver =
  Schema.(
    obj("Message", ~doc="User notification message", ~fields=_ =>
      [
        field(
          "id",
          ~doc="Unique identifier of message",
          ~typ=non_null(int),
          ~args=Arg.[],
          ~resolve=(_info: Context.t, p) =>
          p.id
        ),
        field(
          "email",
          ~doc="Unique identifier of message",
          ~typ=non_null(string),
          ~args=Arg.[],
          ~resolve=(_info, p) =>
          p.email
        ),
        field(
          "message",
          ~doc="Unique identifier of message",
          ~typ=non_null(string),
          ~args=Arg.[],
          ~resolve=(_info, p) =>
          p.message
        ),
      ]
    )
  );

module Config = {
  type nodeType = t;
  type context = Context.t;
  let nodeResolver = resolver;
  let nodeName = "Message";
};

module Connection = Connection.Make(Config);
